#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "Form.h"

class Form;

class Bureaucrat
{
public :

    Bureaucrat();
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat const &other);
    std::string getName(void) const;
    int         getGrade(void) const;

    class GradeTooHighException : public std::exception
    {
     public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    void increaseGrade(void);
    void decreaseGrade(void);
    void signForm(Form& form);
    private : std::string const _name;
    int                  _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
