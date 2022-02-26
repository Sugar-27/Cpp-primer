#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include "StrBlob.h"

using namespace std;

class QueryResult;

class TextQuery {
   public:
    typedef StrBlob::size_type line_no;

    TextQuery(ifstream& fin);

    QueryResult query(const string&) const;

   private:
    StrBlob file;
    map<string, shared_ptr<set<line_no>>> wordmap;
};

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);

   public:
    QueryResult(const string& sought,
                shared_ptr<set<TextQuery::line_no>> sp_l,
                StrBlob file)
        : sought(sought), sp_lines(sp_l), file(file) {}

    const StrBlob& getFile() const { return file; }

    set<TextQuery::line_no>::iterator begin() { return sp_lines->begin(); }
    set<TextQuery::line_no>::iterator end() { return sp_lines->end(); }

   private:
    string sought;
    shared_ptr<std::set<TextQuery::line_no>> sp_lines;
    StrBlob file;
};

TextQuery::TextQuery(ifstream& fin)
    : file(StrBlob()), wordmap(map<string, shared_ptr<set<line_no>>>()) {
    string line;
    while (getline(fin, line)) {
        file.push_back(line);
        int n = file.size() - 1;
        stringstream lineStream(line);
        string word;
        while (lineStream >> word) {
            if (!wordmap[word]) {
                wordmap[word].reset(new set<line_no>());
            }
            wordmap[word]->insert(n);
        }
    }
}
QueryResult TextQuery::query(const string& sought) const {
    static shared_ptr<set<line_no>> noData(new set<line_no>());
    auto iter = wordmap.find(sought);
    if (iter == wordmap.end()) {
        return QueryResult(sought, noData, file);
    } else {
        return QueryResult(sought, iter->second, file);
    }
}

ostream& print(std::ostream& os, const QueryResult& qr) {
    os << qr.sought << " occurs " << qr.sp_lines->size() << " "
       << "times"
       << "\n";

    // print each line in which the word appears
    for (auto& index : *qr.sp_lines) {
        os << "\t(line " << index + 1 << ") ";
        const StrBlobPtr wp(qr.file, index);
        os << wp.deref() << "\n";
    }
    return os;
}

#endif