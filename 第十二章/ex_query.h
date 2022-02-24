#ifndef ex_query_H
#define ex_query_H

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult;
class TextQuery {
   public:
    using line_no = std::vector<string>::size_type;
    TextQuery(std::ifstream& input);
    QueryResult query(const string&) const;

   private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> record;
};

class QueryResult {
   public:
    QueryResult(string word,
                shared_ptr<set<TextQuery::line_no>> ptr,
                shared_ptr<vector<string>> f)
        : word(word), lines(ptr), f(f) {}
    friend std::ostream& print(std::ostream& out, const QueryResult& qr);

   private:
    string word;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> f;
};



#endif