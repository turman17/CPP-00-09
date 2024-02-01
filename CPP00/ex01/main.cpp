#include "Contact.hpp"
#include "Phonebook.hpp"
#include <sstream>
#include <iostream>
#include <string>

void get_contact_info(Contact& contact)
{
    std::string input1, input2, input3, input4, input5;
    
    std::cout << "first name: ";
    std::getline(std::cin, input1);
    std::cout << "last name: ";
    std::getline(std::cin, input2);
    std::cout << "nickname: ";
    std::getline(std::cin, input3);
    std::cout << "phone number: ";
    std::getline(std::cin, input4);
    std::cout << "darkest secret: ";
    std::getline(std::cin, input5);
    if(input1.empty() || input2.empty() || input3.empty() || input4.empty() || input5.empty())
    {
        std::cout << "Invalid input\n";
        get_contact_info(contact);
    }
    contact.set_Contact(input1, input2,  input3, input4, input5);
}

std::string trimString(const std::string &str, size_t maxLength)
{
    if (str.length() > maxLength)
        return str.substr(0, maxLength - 1) + ".";
    return str;
}

int main()
{
    Contact contact;
    phonebook phonebook;
    std::string input;
    
    std::cout << " The program only accepts ADD, SEARCH and EXIT\n";
    while(input != "EXIT"){
        std::getline(std::cin, input);
        if(input == "SEARCH"){
            phonebook.show_library();
            continue;    
        }
        if(input == "ADD")
        {
            get_contact_info(contact);
            phonebook.push_phonebook(contact);
        }
    }
    std::cout << "\nThanks for typing " << input <<"\n";
}