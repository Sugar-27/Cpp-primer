#include "ex_12_30.h"
#include <algorithm>
#include <sstream>
using std::istringstream;
using std::set;

TextQuery::TextQuery(std::ifstream& ifs) : input(new vector<string>) {
    string text;
    while (getline(ifs, text)) {
        input->push_back(text);
        int n = input->size() - 1;  // 当前行号
        istringstream line(text);
        string word;
        while (line >> word) {
            shared_ptr<set<lineNo>>& lines = result[word];
            if (!lines) {
                lines.reset(new set<lineNo>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& str) const {
    static shared_ptr<set<lineNo>> nodata(new set<lineNo>);
    auto loc = result.find(str);
    if (loc == result.end()) {
        return QueryResult(str, nodata, input);
    } else {
        return QueryResult(str, loc->second, input);
    }
}

std::ostream& print(std::ostream& out, const QueryResult& qr) {
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times ":"time") << std::endl;
    for (auto num : *qr.nos) {
        out << "\t(line " << num + 1 << ")"
        << qr.input->at(num) << std::endl;
    }
    return out;
}