#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	a;
	FragTrap	b("Morgan");
	ClapTrap	c("Hugues");
	ScavTrap	d("Ben");

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.takeDamage(3);
	std::cout << b << std::endl;
	b.takeDamage(20);
	std::cout << b << std::endl;
	b.beRepaired(3);
	std::cout << b << std::endl;
	b.attack("Eric");
	b.attack("Eric");
	std::cout << b << std::endl;
	b.attack("Eric");
	std::cout << b << std::endl;
	b.beRepaired(100);
	std::cout << b << std::endl;
	b.attack("Eric");
}