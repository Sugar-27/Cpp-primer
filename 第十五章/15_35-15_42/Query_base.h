#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "Query.h"
#include "TextQuery.h"

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

#endif