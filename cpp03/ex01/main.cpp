#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void section(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	section("Construction chaining (named constructor)");
	{
		std::cout << ">>> about to construct a ScavTrap named Vulcan" << std::endl;
		ScavTrap vulcan("Vulcan");
		std::cout << ">>> ScavTrap Vulcan fully constructed" << std::endl;
		// Expect to see ClapTrap's own creation message printed FIRST,
		// then ScavTrap's creation message - proving the base is built before
		// the derived constructor body runs.
	}
	std::cout << ">>> Vulcan should be destroyed by now (reverse order: ScavTrap first, then ClapTrap)" << std::endl;

	section("Default constructor");
	{
		ScavTrap defaultTrap;
		defaultTrap.attack("Nobody");
	}

	section("Stat overrides (100 hp / 50 energy / 20 dmg)");
	{
		ScavTrap sabre("Sabre");
		sabre.attack("Target"); // should show 20 damage, not ClapTrap's 0
	}

	section("guardGate()");
	{
		ScavTrap tango("Tango");
		tango.guardGate();
	}

	section("Copy constructor and copy assignment");
	{
		ScavTrap uniform("Uniform");
		uniform.attack("Target");
		ScavTrap uniformCopy(uniform);
		uniformCopy.attack("Target");

		ScavTrap victor("Victor");
		victor = uniform;
		victor.attack("Target");
	}

	section("Death and energy depletion still work via inherited logic");
	{
		ScavTrap whiskey("Whiskey");
		whiskey.takeDamage(150); // more than 100 hp -> should die, no underflow
		whiskey.attack("Nobody");    // should refuse: dead
		whiskey.guardGate();         // should refuse: dead

		ScavTrap xray("Xray");
		for (int i = 0; i < 50; i++)
			xray.attack("Punching bag"); // 50 energy -> all should succeed
		xray.attack("Punching bag");     // 51st: should refuse, no energy
		xray.guardGate();                // should also refuse: no energy
	}

	section("Polymorphism check: ClapTrap& referring to a ScavTrap");
	{
		ScavTrap yankee("Yankee");
		ClapTrap &asBase = yankee;
		asBase.attack("Target");
		// Since ClapTrap::attack is NOT virtual (ex01 doesn't require virtual yet),
		// this is expected to call ClapTrap's version, not ScavTrap's -
		// worth checking whether that matches what you see, and why.
	}

	section("Done");
	return (0);
}
