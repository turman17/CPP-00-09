#include "RobotomyRequestForm.h"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Def", 100, 100)
{
    // std::cout << "Def constructor was called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, "robotomy request", 25, 5), _target(target)
{
    // std::cout << "Def constructor was called\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
:AForm(other)
{
    // std::cout << "Copy const was called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "Def destructor was called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() <= getToExecute())
    {
        std::cout << this->_target << " drill drill drrrrriiiillllllll" << std::endl;
        int random = std::rand() % 2;
        if (random == 0)
            std::cout << this->_target << " has been robotomized successfully." << std::endl;
        else
            std::cout << this->_target << " robotomization failed." << std::endl;
    }
}