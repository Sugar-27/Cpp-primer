#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"

class Query_Base {
    friend class Query;
    protected:
        using inline_no = TextQuery::line_no
}

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
}

#endif