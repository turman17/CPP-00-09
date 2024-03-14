#include "Intern.h"

Intern::Intern()
{
    // std::cout << "def const was called\n";
}

Intern::Intern(Intern const& other)
{
    (void)other;
    // std::cout << "copy const was called\n";
}

Intern& Intern::operator=(Intern const &other)
{
    (void)other;
    return(*this);
}

Intern::~Intern()
{
    // std::cout << "destructor was called\n";
}

const char *Intern::FormDoesNotExist::what() const throw()
{
    return ("Form does not exist");
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    try
    {
        AForm *form[3] = {
            new RobotomyRequestForm(target),
            new PresidentialPardonForm(target),
            new ShrubberyCreationForm(target)};
        for (int i = 0; i < 3; i++)
        {
            if (form[i]->getName() == formName)
            {
                std::cout << "Intern creates " << formName << std::endl;
                for (int j = 0; j < 3; j++)
                {
                    if (j != i)
                        delete form[j];
                }
                return (form[i]);
            }
        }
        for (int j = 0; j < 3; j++)
            delete form[j];
        throw Intern::FormDoesNotExist();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (NULL);
}
