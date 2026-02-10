#include "Harl.h"

Harl::Harl()
{
 //  std::cout << "Harl created :D" << std::endl;
}

Harl::~Harl()
{
   // std::cout << "Harl destroyed D:" << std::endl;
}


void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void    Harl::complain( std:: string level )
{

    int maxlen = 4 ;
    int index = -1;
    std::string arrLevel[maxlen] = { "DEBUG", "INFO", "WARNING", "ERROR"};



    for (int i = 0; i < maxlen; i++)
    {
        if (level == arrLevel[i])
        {
            index = i; 
            break ;
        }
    }

    switch (index)
    {
        case 0: 
            std::cout << "[ DEBUG ]" << std::endl;
            this->debug();
             /* fall through */
        case 1: 
            std::cout << "[ INFO ]" << std::endl;
            this->info();
             /* fall through */
        case 2: 
            std::cout << "[ WARNING ]" << std::endl;
            this->warning();
             /* fall through */
        case 3: 
            std::cout << "[ ERROR ]" << std::endl;
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
