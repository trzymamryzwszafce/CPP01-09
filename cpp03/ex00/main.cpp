#include "ClapTrap.hpp"

int main()
{
	ClapTrap defcontsruct;
	ClapTrap oopygoopy("oopygoopy");
	ClapTrap copy(oopygoopy);
	ClapTrap assignment("generalmunchkinman");

	defcontsruct = assignment;

	std::cout << "\n Main ClapTrap (death)\n\n";
	oopygoopy.attack("liljimbob");
	oopygoopy.beRepaired(10);
	oopygoopy.takeDamage(90);
	oopygoopy.attack("liljimbob");
	oopygoopy.beRepaired(10);

	std::cout << "\n Assignment ClapTrap (energy depletion)\n\n";
	defcontsruct.attack("liljimbob");
	for (int i = 0; i < 12; i++)
		defcontsruct.beRepaired(10);
	defcontsruct.attack("liljimbob");
	std::cout << std::endl;
}
