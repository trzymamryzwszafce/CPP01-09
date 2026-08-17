#include "ClapTrap.hpp"
#include <ostream>

ClapTrap::ClapTrap(const std::string& clapName) : name(clapName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : name(obj.name), hitPoints(obj.hitPoints), energyPoints(obj.energyPoints), attackDamage(obj.attackDamage)
{
	std::cout << "Copy of "<< obj.name << " created" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "ClapTrap " << this->name << " overwritten by " << obj.name << std::endl;
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks "<< target <<", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
	{
		if (this->hitPoints == 0)
			std::cout << "ClapTrap " << this->name << " can't attack cause it's dead ☠️" << std::endl;
		else
			std::cout << "ClapTrap " << this->name << " have no energy" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't repair cause it's dead ☠️" << std::endl;
		return;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " have no energy to repair" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " healed for " << amount << " points of hp" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead ☠️" << std::endl;
		return;
	}
	else if (this->hitPoints <= amount)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " died ☠️" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage" << std::endl;
	this->hitPoints -= amount;
}
