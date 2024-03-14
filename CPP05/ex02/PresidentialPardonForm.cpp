#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Def", 150, 100)
{
    std::cout << "Def const called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Def", 150, 100), _target(target)
{
    std::cout << "Def const called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
: AForm(other)
{
    std::cout << "Copy const called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Def destructor called\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() <= getToExecute())
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
    else
        throw ProblemToExecute();
}
