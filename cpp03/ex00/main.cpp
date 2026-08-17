#include "ClapTrap.hpp"

void section(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	section("Basic construction and destruction");
	{
		ClapTrap a("Alpha");
	}
	std::cout << "(Alpha should be destroyed by now)" << std::endl;

	section("Normal attack / takeDamage / beRepaired flow");
	{
		ClapTrap bravo("Bravo");
		bravo.attack("Dummy");
		bravo.takeDamage(3);
		bravo.beRepaired(2);
	}

	section("Copy constructor and copy assignment");
	{
		ClapTrap charlie("Charlie");
		charlie.takeDamage(4);
		ClapTrap charlieCopy(charlie); // copy constructor
		charlieCopy.attack("Target");

		ClapTrap delta("Delta");
		delta = charlie; // copy assignment
		delta.attack("Target");
	}

	section("Death by takeDamage (exact hitPoints)");
	{
		ClapTrap echo("Echo");
		echo.takeDamage(10); // exactly hitPoints -> should die
		echo.attack("Nobody");    // should refuse: dead
		echo.beRepaired(5);       // should refuse: dead
		echo.takeDamage(1);       // should refuse: already dead
	}

	section("Death by takeDamage (overkill)");
	{
		ClapTrap foxtrot("Foxtrot");
		foxtrot.takeDamage(9999); // way more than hitPoints -> should die, no underflow
		foxtrot.attack("Nobody"); // should refuse: dead
	}

	section("Energy depletion (attack drains energy to 0)");
	{
		ClapTrap golf("Golf");
		// energyPoints starts at 10, each attack costs 1
		for (int i = 0; i < 10; i++)
			golf.attack("Punching bag");
		golf.attack("Punching bag"); // 11th attack: should refuse, no energy left
		golf.beRepaired(1);          // should also refuse: no energy left
	}

	section("Energy depletion (beRepaired drains energy to 0)");
	{
		ClapTrap hotel("Hotel");
		hotel.takeDamage(5); // so beRepaired has something to actually restore
		for (int i = 0; i < 10; i++)
			hotel.beRepaired(1);
		hotel.beRepaired(1); // 11th repair: should refuse, no energy left
		hotel.attack("Nobody"); // should also refuse: no energy left
	}

	section("Done");
	return (0);
}
