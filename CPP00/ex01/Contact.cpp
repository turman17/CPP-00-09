#include "Contact.hpp"

void Contact::set_Contact(std::string name, std::string last, std::string nick, std::string number, std::string secret) {
    first_name = name;
    last_name = last;
    nickname = nick;
    phone_number = number;
    darkest_secret = secret;
}

void Contact::get_Contact() {
    std::cout << " " << trimString(first_name, 9);
    std::cout << "| " << trimString(last_name, 9);
    std::cout << "| " << trimString(nickname, 9);
    std::cout << "| " << trimString(phone_number, 9) << "\n";
}

void Contact::display_full() {
    std::cout << " " << first_name;
    std::cout << "| " << last_name;
    std::cout << "| " << nickname;
    std::cout << "| " << phone_number;
    std::cout << "| " << darkest_secret << "\n";
}
