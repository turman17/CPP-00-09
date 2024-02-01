#include " Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main()
{
    randomChump("vIKTOR");
    Zombie *d = newZombie("Viktor");
    d->announce();
    delete d;
    return 0;
}