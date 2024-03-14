
#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main(void)
{
    // srand(time(NULL));
    Intern someRandomIntern;
    AForm *rrf;
    AForm *scf;
    AForm *ppf;
    AForm *unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Wall-e");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Clinton");
    unknown = someRandomIntern.makeForm("unknown", "unknown");

    delete rrf;
    delete scf;
    delete ppf;
    delete unknown;
    return (0);
}