#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
  
}

void Weapon::setType(std::string _type)
{
    type = _type;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

Weapon::~Weapon()
{

}