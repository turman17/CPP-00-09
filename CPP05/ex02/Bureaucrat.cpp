#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() 
    : _name("DefName"), _grade(100)
{
    std::cout << "Def constructor was called\n";
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    :_name(name)
{
    try
    {
        if(grade > 150)
            throw GradeTooLowException();
        else if(grade < 1)
            throw GradeTooHighException();
        else
            _grade = grade;
    }
    catch (std::exception &e)
    {
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    :_name(other._name), _grade(other._grade){
    std::cout << "Copy constructor was called\n";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
    if(this != &other)
    {
        _grade = other._grade;
    }
    std::cout << "Assign opertator was called\n";
    return(*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Def destructor was called\n";
}

std::string Bureaucrat::getName() const
{
    return(this->_name);
}

int Bureaucrat::getGrade() const
{
    return(this->_grade);
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
    return("Grade is too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
    return("Grade is too Low");
}

void Bureaucrat::increaseGrade(){
    try
    {
        if(_grade > 150)
            throw GradeTooLowException();
        else if (_grade == 1)
            std::cout << "No way to increase\n";
        else if (_grade < 1) 
            throw GradeTooHighException();
        else
            _grade -= 1;
    }
    catch(std::exception &e)
    {
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (!form.getIsSigned())
    {
        std::cout << "The form must be signed before execution..." << std::endl;
        return;
    }
    else if (_grade >= form.getToExecute())
    {
        std::cout << "Grade too low..." << std::endl;
        return;
    }
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to execute form: " << e.what() << std::endl;
    }
    
}

void Bureaucrat::decreaseGrade()
{
    try
    {
        if (_grade > 150)
            throw GradeTooLowException();
        else if (_grade == 1)
            std::cout << "No way to increase\n";
        else if (_grade < 1)
            throw GradeTooHighException();
        _grade += 1;
    }
    catch (std::exception &e)
    {
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    os << std::endl;
    return os;
}

