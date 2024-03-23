
#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    bool              _isSigned;
    int const _toSign;
    int const _toExecute;
public:
    Form();
    Form(std::string name, int isSigned, int toexecute);
    Form(Form const& other);
    ~Form();
    Form &operator=(Form const &other);

    std::string getName(void) const;
    bool getIsSigned() const;
    int getToSign() const;
    int getToExecute() const;
    void beSigned(Bureaucrat const &Bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeIsSigned : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

};

std::ostream& operator<<(std::ostream &os, Form const& form);

#endif