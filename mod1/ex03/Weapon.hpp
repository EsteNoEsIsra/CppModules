#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;



public:
    Weapon(std::string type);
    ~Weapon();

    std::string getType() const { return type; };
    std::string setType(std::string _type);
};

#endif