#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

std::string trimString(const std::string &str, size_t maxLength);

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void set_Contact(std::string name, std::string last, std::string nick, std::string number, std::string secret);
    void get_Contact();
    void display_full();
    void get_contact_info(Contact &contact);
};

#endif