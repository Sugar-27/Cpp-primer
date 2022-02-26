#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include "StrBlob.h"
#include "TextQuery.h"

using namespace std;

// 抽象基类，具体的查询类型从中派生，所有成员均private
class Query_base {
    friend class Query;

   protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

   private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const string& s) : queryword(s) {}

    QueryResult eval(const TextQuery& t) const override {
        return t.query(queryword);
    }
    string rep() const override {
        cout << "WodQuery::rep()" << endl;
        return queryword;
    }

    string queryword;  // 要查找的单词
};

// 用于管理Query_base的接口类
class Query {
    friend Query operator&(const Query& lhs, const Query& rhs);
    friend Query operator|(const Query& lhs, const Query& rhs);
    friend Query operator~(const Query& lhs);

   public:
    Query(const string& s) : q(new WordQuery(s)) {
        cout << "Query::Query(const std::string& s) where s=" << s << endl;
    }
    QueryResult eval(const TextQuery& t) const { return q->eval(t); }
    string rep() const {
        cout << "Query::rep()" << endl;
        return q->rep();
    }

   private:
    // 给友元函数用来构造的
    Query(shared_ptr<Query_base> query) : q(query) {
        cout << "Query::Query(std::shared_ptr<Query_base> query)" << endl;
    }
    shared_ptr<Query_base> q;
};

inline ostream& operator<<(ostream& os, const Query& query) {
    return os << query.rep();
}

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
    QueryResult right = rhs.eval(text), left = lhs.eval(text);
    shared_ptr<set<line_no>> ret_lines =
        make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.getFile());
}
inline Query operator|(const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
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