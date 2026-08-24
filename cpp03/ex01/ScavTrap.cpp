/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <szmadeja@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:59:49 by szmadeja          #+#    #+#             */
/*   Updated: 2026/08/24 18:56:49 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap created" << std::endl;
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& scavName) : ClapTrap(scavName)
{
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy of "<< obj.name << " created" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{	
		std::cout << "ScavTrap " << this->name << " overwritten by " << obj.name << std::endl;
		ClapTrap::operator=(obj);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
	{
		if (this->hitPoints == 0)
			std::cout << "ScavTrap " << this->name << " can't attack cause it's dead ☠️" << std::endl;
		else
			std::cout << "ScavTrap " << this->name << " have no energy to attack" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " can't guard cause it's dead ☠️" << std::endl;
		return;
	}
	else if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " have no energy to guard" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is in Gate keeper mode!" << std::endl;
}
