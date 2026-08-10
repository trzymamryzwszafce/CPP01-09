#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

void	Weapon::setType(std::string parameter)
{
	this->_type = parameter;
}

const std::string&	Weapon::getType()
{
	return _type;
}
