#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie{

    private: 
        std::string name;
        
    public:
        void announce( void );

        Zombie();
        ~Zombie();

        Zombie newZombie(std::string name);
        void randomChump(std::string name);

        void setName(std::string _name);      
        std::string getName() {return (name);}

};


#endif