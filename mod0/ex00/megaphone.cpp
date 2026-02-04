#include <iostream>

std::string to_uppercase(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

int main(int ar, char **av)
{
    if (ar == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else 
    {
        for (int i = 1; i < ar; i++)
        {
            std::cout << to_uppercase(av[i]);
        }
       std::cout << std::endl;
    }
    return (0);
}