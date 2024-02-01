#include "Phonebook.hpp"
#include "Contact.hpp"

void phonebook::push_phonebook(Contact &contact)
    {
        if (count < 8)
        {
            Phonebook[count] = contact;
            count++;
        }
        else
        {
            for (int i = 1; i < 8; i++)
            {
                Phonebook[i - 1] = Phonebook[i];
            }
            Phonebook[7] = contact;
        }
    }
    void phonebook::show_library()
    {
        std::string input;
        int index;
        std::cout << "  Index | First Name | Last Name | Nickname\n";
        std::cout << "--------------------------------------------\n";
        for (int i = 0; i < count; i++)
        {
            std::cout << i + 1 << " |";
            Phonebook[i].get_Contact();
        }
        std::cout << "\nWhich contact do you want to see? (Enter Index)\n";
        std::getline(std::cin, input);
        std::istringstream iss(input);

        if (iss >> index && index > 0 && index <= count)
            Phonebook[index - 1].display_full();
        else
        {
            std::cout << "Wrong Index\n";
            show_library();
        }
    }