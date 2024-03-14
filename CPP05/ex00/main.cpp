#include "Bureaucrat.h"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("Vittor", 1);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 150);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 0);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 151);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 2);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 149);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 3);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 148);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 4);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 147);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    bureaucrat = new Bureaucrat("Vittor", 5);
    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    return (0);
}