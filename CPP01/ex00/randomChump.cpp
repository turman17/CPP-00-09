#include " Zombie.hpp"
#include <sstream>

void randomChump( std::string name )
{
    Zombie zomb(name);
    zomb.announce();
}