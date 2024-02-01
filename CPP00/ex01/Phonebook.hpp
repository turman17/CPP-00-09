#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Contact.hpp"


class phonebook
{
private:
    Contact Phonebook[8];
    int count;

public:
    phonebook() : count(0) {}
    void push_phonebook(Contact &contact);
    void show_library();
};

#endif