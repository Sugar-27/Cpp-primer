#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "BinaryQuery.h"
#include "NotQuery.h"
#include "Query.h"
#include "Query_base.h"
#include "StrBlob.h"
#include "TextQuery.h"

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const string& s) : queryword(s) {}
    string queryword;  // 要查找的单词
    QueryResult eval(const TextQuery& t) const override {
        return t.query(queryword);
    }
    string rep() const {
        cout << "WodQuery::rep()" << endl;
        return queryword;
    }
};

#endif