#include "ex_query.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream& ifs) : file(new vector<string>) {
    string text;
    while (getline(ifs, text)) {
        file->push_back(text);
        std::istringstream line(text);
        string word;
        while (line >> word) {
            if (record.find(word) == record.end()) {
                record[word].reset(new set<line_no>);
            }
            record[word]->insert(file->size() - 1);
        }
    }
}

QueryResult TextQuery::query(const string& word) const {
    auto q = record.find(word);
    static shared_ptr<set<line_no>> no_data(new set<line_no>);
    if (q == record.end()) {
        return QueryResult(word, no_data, file);
    } else {
        return QueryResult(word, q->second, file);
    }
}

std::ostream& print(std::ostream& out, const QueryResult& qr) {
    out << qr.word << " 出现了 " << qr.lines->size() << "次" << std::endl;
    for (auto line : *qr.lines) {
        out << "(line " << line + 1 << ")" << qr.f->at(line) << std::endl;
    }
    return out;
}