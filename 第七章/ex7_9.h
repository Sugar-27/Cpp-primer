#ifndef ex7_9_h
#define ex7_9_h

#include <string>
#include <iostream>

class Person
{
public:
    std::string const &getname() const { return name; }
    std::string const &getAddress() const { return address; }
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, Person &person)
{
    os << person.name << ' ' << person.address;
}

#endif