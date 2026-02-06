#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    setType(type);
}

void Weapon::setType(std::string _type)
{
    this->type = _type;
}
Weapon::~Weapon()
{

}