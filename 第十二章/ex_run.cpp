#include "ex_query.h"
#include <iostream>

void runQuery(std::ifstream& ifs) {
    TextQuery file(ifs);
    while (true) {
        std::cout << "请输入要查询的单词或按q退出：";
        string word;
        if (!(std::cin >> word) || word == "q") {
            break;
        }
        print(std::cout, file.query(word));
    }
}

int main() {

    std::ifstream inputFile("./storyDataFile.txt");
    runQuery(inputFile);

    return 0;
}