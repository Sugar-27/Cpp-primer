#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "Query_base.h"
#include "TextQuery.h"

class BinaryQuery : public Query_base {
   protected:
    BinaryQuery(const Query& l, const Query& r, string s)
        : lhs(l), rhs(r), opSym(s) {
        cout << "BinaryQuery::BinaryQuery()  where s=" << s << endl;
    }
    string rep() const override {
        cout << "BinaryQuery::rep()" << endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    string opSym;  // 运算符
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right)
        : BinaryQuery(left, right, "|") {
        cout << "OrQuery::OrQuery()" << endl;
    }
    QueryResult eval(const TextQuery&) const override;
};
QueryResult OrQuery::eval(const TextQuery& text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.getFile());
}
inline Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "&") {}
    QueryResult eval(const TextQuery&) const override;
};
QueryResult AndQuery::eval(const TextQuery& text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    /* 自己的做法 */
    // auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    // for (auto iter = right.begin(); iter != right.end(); ++iter) {
    //     if (ret_lines->find(*iter) == ret_lines->end()) {
    //         ret_lines->erase(*iter);
    //     }
    // }
    /* 书上的做法 */
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.getFile());
}
inline Query operator&(const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
#endif