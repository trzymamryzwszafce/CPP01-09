#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap created" << std::endl;
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string& fragName) : ClapTrap(fragName)
{
	std::cout << "FragTrap " << this->name << " created" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "Copy of "<< obj.name << " created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "FragTrap " << this->name << " overwritten by " << obj.name << std::endl;
		ClapTrap::operator=(obj);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " have no hp to request a high five ☠️" << std::endl;
		return;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " have no energy to request a high five" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " request a high five!" << std::endl;
}
