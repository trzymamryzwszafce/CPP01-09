#include "Zombie.hpp"

int	main()
{
	std::cout << "heap zombie:\n\n"; 

	Zombie *heap = newZombie("OopyGoopy");
	heap->announce();
	delete heap;

	std::cout << "\nstack zombie:\n\n";
	randomChump("LilJimBob");

	return 0;
}
