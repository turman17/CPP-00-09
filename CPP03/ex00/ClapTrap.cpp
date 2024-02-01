#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Defoult"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Def constructor is called\n";
}

ClapTrap::ClapTrap(std::string const &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::ClapTrap(ClapTrap const &other)
	: _name(other._name), _hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
    if(_energyPoints > 0 && _hitPoints > 0){
        _energyPoints--;
	    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!\n";
    }
    else
        std::cout << "Error\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
	    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
    }
    else 
	    std::cout << "ClapTrap " << _name << " is dead!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
	    std::cout << "ClapTrap " << _name << " repairs itself with " << amount << " points of health!\n";
	}
    else
        std::cout << "Error\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "distructor is called\n";
}
