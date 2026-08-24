#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap defcontsruct;
	FragTrap oopygoopy("oopygoopy");
	FragTrap copy(oopygoopy);
	FragTrap assignment("generalmunchkinman");

	defcontsruct = assignment;

	std::cout << "\n Main FragTrap (death)\n\n";
	oopygoopy.attack("liljimbob");
	oopygoopy.beRepaired(10);
	oopygoopy.highFivesGuys();
	oopygoopy.takeDamage(120);
	oopygoopy.attack("liljimbob");
	oopygoopy.beRepaired(10);
	oopygoopy.highFivesGuys();

	std::cout << "\n Assignment FragTrap (energy depletion)\n\n";
	defcontsruct.attack("liljimbob");
	for (int i = 0; i < 102; i++)
		defcontsruct.beRepaired(10);
	defcontsruct.attack("liljimbob");
	defcontsruct.highFivesGuys();
	std::cout << std::endl;
}
