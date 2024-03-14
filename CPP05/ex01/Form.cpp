# include "Form.h"

Form::Form() 
: _name("defName"), _isSigned(false), _toSign(100), _toExecute(100)
{
    std::cout << "DEF const was called\n";
}

Form::Form(std::string const &name, int const toSign, int const toExecute)
    : _name(name), _isSigned(false), _toSign(toSign), _toExecute(toExecute)
{
    std::cout << "Constructor was called\n";
}

Form::Form(Form const &other)
: _name(other._name), _isSigned(other._isSigned), _toSign(other._toSign), _toExecute(other._toExecute)
{
    std::cout << "Copy Constructor was called\n";
}

Form& Form::operator=(Form const &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return(*this);
}

Form::~Form()
{
    std::cout << "Destractor was called\n";
}

std::string Form::getName(void) const
{
    return(_name);
}

bool Form::getIsSigned() const
{
    return(_isSigned);
}

int Form::getToSign() const
{
    return(_toSign);
}

int Form::getToExecute() const
{
    return(_toExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (_isSigned)
    {
        throw GradeIsSigned(); // Exception indicating form is already signed
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

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low");
}

const char *Form::GradeIsSigned::what() const throw()
{
    return ("Grade is Signed");
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
    os << form.getName() << ", signed: " << (form.getIsSigned() ? "Yes" : "No");
    os << ", grade required to sign: " << form.getToSign();
    os << ", grade required to execute: " << form.getToExecute() << std::endl;
    return os;
}
