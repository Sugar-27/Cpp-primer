#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "BinaryQuery.h"
#include "Query.h"
#include "Query_base.h"
#include "StrBlob.h"
#include "TextQuery.h"
#include "WordQuery.h"

class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query(q) {}
    QueryResult eval(const TextQuery&) const;
    string rep() const { return "~(" + query.rep() + ")"; }

    Query query;
};
QueryResult NotQuery::eval(const TextQuery& text) const {
    QueryResult result = query.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    // 一共有sz行，选出其中不在result中的，加入ret_lines
    size_t sz = result.getFile().size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n) {
            ret_lines->insert(n);
        } else if (beg != end) {
            beg++;
        }
    }
    return QueryResult(rep(), ret_lines, result.getFile());
}

inline Query operator~(const Query& operand) {
    // return语句隐式地使用接受一个shared_ptr<Query_base>的Query构造函数
    return shared_ptr<Query_base>(new NotQuery(operand));
}

#endif