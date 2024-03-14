# include "AForm.h"

AForm::AForm() 
: _name("defName"), _isSigned(false), _toSign(100), _toExecute(100)
{
    // std::cout << "DEF const was called\n";
}

AForm::AForm(std::string const &name, int const toSign, int const toExecute)
    : _name(name), _isSigned(false), _toSign(toSign), _toExecute(toExecute)
{
    // std::cout << "Constructor was called\n";
}

AForm::AForm(AForm const &other)
: _name(other._name), _isSigned(other._isSigned), _toSign(other._toSign), _toExecute(other._toExecute)
{
    // std::cout << "Copy Constructor was called\n";
}

AForm& AForm::operator=(AForm const &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return(*this);
}

AForm::~AForm()
{
    // std::cout << "Destractor was called\n";
}

std::string AForm::getName(void) const
{
    return(_name);
}

bool AForm::getIsSigned() const
{
    return(_isSigned);
}

int AForm::getToSign() const
{
    return(_toSign);
}

int AForm::getToExecute() const
{
    return(_toExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (_isSigned)
    {
        throw GradeIsSigned(); // Exception indicating AForm is already signed
    }
    else if (bureaucrat.getGrade() > _toSign)
    {
        throw GradeTooLowException(); // Exception indicating bureaucrat's grade is too low
    }
    else
    {
        _isSigned = true;
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too High");
}

const char *AForm::ProblemToExecute::what() const throw()
{
    return ("No way to execute: Error 404");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low");
}

const char *AForm::GradeIsSigned::what() const throw()
{
    return ("Grade is Signed");
}

std::ostream &operator<<(std::ostream &os, AForm const &AForm)
{
    os << AForm.getName() << ", signed: " << (AForm.getIsSigned() ? "Yes" : "No");
    os << ", grade required to sign: " << AForm.getToSign();
    os << ", grade required to execute: " << AForm.getToExecute() << std::endl;
    return os;
}

AForm::AForm(std::string target, std::string name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _toSign(gradeToSign),
      _toExecute(gradeToExecute),
      _target(target)
{
    try
    {
        if (gradeToSign < 1)
            throw AForm::GradeTooHighException();
        else if (gradeToSign > 150)
            throw AForm::GradeTooLowException();
        else
            this->_isSigned = false;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}