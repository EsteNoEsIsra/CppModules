#include "Harl.h"

int main(int ar, char **av)
{
    if (ar == 2)
    {
        std::string arg = av[1];
        Harl *harl = new Harl();

        harl->complain(arg);

        delete harl;
    }
    else
    { 
        std::cout << "Usage: ./harlFilter \"level\" " << std::endl;
        std::cout << "Levels : \"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\" " << std::endl;
    }
    return 0;
}