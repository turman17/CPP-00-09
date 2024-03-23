#include "Bureaucrat.h"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

int main()
{
    try
    {
        Bureaucrat Vittor("Vittor", 151);
        std::cout << Vittor << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Vittor("Vittor", 100);
        std::cout << Vittor << std::endl;
        Vittor.decreaseGrade();
        std::cout << Vittor << std::endl;
        Vittor.increaseGrade();
        Vittor.increaseGrade();
        std::cout << Vittor << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Vittor("Vittor", -1);
        std::cout << Vittor << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
    return (0);
}