#include " Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {

    int n = 7;
    std::string zombie = "BooB";
    Zombie* myHorde = zombieHorde(n, zombie);
    for(int i = 0; i < n; i++)
        myHorde[i].announce();
    delete[] myHorde;
    return 0;
}