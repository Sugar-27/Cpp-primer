#ifndef ex_12_30_h
#define ex_12_30_h

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <fstream>
#include <iostream>
#include <map>
#include <set>

class QueryResult;
// 保存输入文件的类，用一个vector来保存文本，用一个set来存行号，用map来关联单词和行号
class TextQuery {
   public:
    using lineNo = vector<string>::size_type;
    // 把整个函数修饰为const,意思是“函数体内不能对成员数据做任何改动”
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;

   private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<lineNo>>> result;
};

// 用于返回内容的类，保存查询结果
class QueryResult {
   public:
    friend std::ostream& print(std::ostream&, const QueryResult&);

   public:
    QueryResult(const string& s,
                shared_ptr<std::set<TextQuery::lineNo>> set,
                shared_ptr<vector<string>> v)
        : word(s), nos(set), input(v) {}

   private:
    string word;
    shared_ptr<std::set<TextQuery::lineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream& print(std::ostream&, const QueryResult&);
#endif
