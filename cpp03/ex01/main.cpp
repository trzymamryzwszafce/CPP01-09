/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <szmadeja@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:00:02 by szmadeja          #+#    #+#             */
/*   Updated: 2026/08/24 18:00:03 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap defcontsruct;
	ScavTrap oopygoopy("oopygoopy");
	ScavTrap copy(oopygoopy);
	ScavTrap assignment("generalmunchkinman");

	defcontsruct = assignment;

	std::cout << "\n Main ScavTrap (death)\n\n";
	oopygoopy.attack("liljimbob");
	oopygoopy.beRepaired(10);
	oopygoopy.guardGate();
	oopygoopy.takeDamage(120);
	oopygoopy.attack("liljimbob");
	oopygoopy.beRepaired(10);
	oopygoopy.guardGate();

	std::cout << "\n Assignment ScavTrap (energy depletion)\n\n";
	defcontsruct.attack("liljimbob");
	for (int i = 0; i < 53; i++)
		defcontsruct.beRepaired(10);
	defcontsruct.attack("liljimbob");
	defcontsruct.guardGate();
	std::cout << std::endl;
}
