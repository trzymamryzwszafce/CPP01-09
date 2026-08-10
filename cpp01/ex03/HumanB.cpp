#include "HumanB.hpp"
#include "Weapon.hpp"
#include <cstddef>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << _name << " has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
