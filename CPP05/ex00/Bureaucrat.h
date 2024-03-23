#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
public :

    Bureaucrat();
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat(std::string name, unsigned int grade);
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
private : 
    std::string const    _name;
    int                  _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
