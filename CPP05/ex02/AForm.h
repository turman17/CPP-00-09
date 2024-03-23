
#ifndef AAForm_H
#define AAForm_H

#include <iostream>
#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(std::string name, int isSigned, int toexecute);
    AForm(AForm const& other);
    virtual ~AForm();
    AForm &operator=(AForm const &other);

    std::string getName(void) const;
    bool        getIsSigned() const;
    int         getToSign() const;
    int         getToExecute() const;
    void        beSigned(Bureaucrat const &Bureaucrat);
    virtual void        execute(Bureaucrat const &executor) const=0;

protected:
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class ProblemToExecute : public std::exception
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
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _toSign;
    int const           _toExecute;
    std::string         _target;
};

std::ostream& operator<<(std::ostream &os, AForm const& AForm);

#endif