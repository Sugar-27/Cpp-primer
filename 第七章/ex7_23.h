#ifndef ex7_23_h
#define ex7_23_h

#include <string>
#include <iostream>

class Screen
{
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[curcor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    pos curcor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};

#endif