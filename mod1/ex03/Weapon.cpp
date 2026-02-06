#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    setType(type);
}

std::string Weapon::setType(std::string _type)
{
    this->type = _type;
    return this->type;
}
Weapon::~Weapon()
{

}