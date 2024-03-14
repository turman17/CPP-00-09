#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "AForm.h"

class AForm;

class Bureaucrat
{
public :
    Bureaucrat();
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    std::string getName(void) const;
    int         getGrade(void) const;
    void increaseGrade(void);
    void decreaseGrade(void);
    void signForm(AForm &form);
    void executeForm(AForm const &form);

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

private : 
    std::string    const _name;
    int                  _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
