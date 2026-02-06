#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    setType(type);
}

std::string Weapon::setType(std::string _type)
{
    type = _type;
    return type;
}
Weapon::~Weapon()
{

}