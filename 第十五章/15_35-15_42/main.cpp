
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Query.h"

int main() {
    std::ifstream file("test.txt");

    TextQuery tQuery(file);

    Query q = Query("fieryzzz") | Query("wind");

    print(cout, q.eval(tQuery));

    return 0;
}
