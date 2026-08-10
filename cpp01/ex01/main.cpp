#include "Zombie.hpp"

int	main()
{
	int i;

	std::cout << "Enter the amount of zombies to create: ";
	std::cin >> i;
	std::cout << "\n";

	Zombie *zombies = zombieHorde(i, "GeneralMunchkinMan");
	for (int j = 0; j < i; j++)
		zombies[j].announce();

	std::cout << std::endl;

	delete[] zombies;

	return 0;
}
