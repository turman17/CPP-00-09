#include <iostream>
// #include <string>
// #include <cctype>

void ft_uppercase(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        std::cout << str[i];
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (i < ac)
        {
            ft_uppercase(av[i]);
            std::cout << "\n";
            i++;
        }
    }
    return 0;
}
