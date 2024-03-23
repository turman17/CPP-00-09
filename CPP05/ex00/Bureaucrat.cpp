
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat()
    : _name("DefName"), _grade(100)
{
    // std::cout << "Def constructor was called\n";
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _grade = grade;
    // std::cout << "Constructor was called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor was called\n";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    std::cout << "Assign opertator was called\n";
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Def destructor was called\n";
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low");
}

void Bureaucrat::increaseGrade()
{
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade == 1)
        std::cout << "No way to increase\n";
    else if (_grade < 1)
        throw GradeTooHighException();
    else
        _grade -= 1;
}

void Bureaucrat::decreaseGrade()
{
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade == 1)
        std::cout << "No way to increase\n";
    else if (_grade < 1)
        throw GradeTooHighException();
    _grade += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}
