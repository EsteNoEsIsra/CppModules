#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>
# include <sstream>

class Zombie{

    private: 
        std::string name;
        
    public:
        void announce( void );

        Zombie();
        Zombie(std::string name);
        ~Zombie();


        void setName(std::string _name);
        std::string getName() const {return (name);}
};

#endif