#include " Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zomb = new Zombie[N];
    for(int i = 0; i < N; i++){
        zomb[i].setter(name);}
    return zomb;
}