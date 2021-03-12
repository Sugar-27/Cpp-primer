#ifndef ex7_5_h
#define ex7_5_h

#include <string>

class Person
{
    std::string name;
    std::string address;

public:
    std::string const &get_name() const { return name; }
    std::string const &get_address() const { return address; };
};

#endif