#ifndef ex7_15_h
#define ex7_15_h

#include <string>
#include <iostream>

struct Person
{
    Person() = default;
    Person(std::string &na, std::string ad) : name(na), address(ad) {}
    Person(std::istream &is) { read(is, *this); }

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