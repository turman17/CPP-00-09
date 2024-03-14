#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "AForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

class Intern {
public:
    Intern();
    Intern(Intern const& other);
    Intern &operator=(Intern const& other);
    ~Intern();
    AForm *makeForm(std::string const &formName, std::string const &target);

    class FormDoesNotExist : public std::exception
    {
    public:
        const char *what() const throw();
    };

private:
};

#endif