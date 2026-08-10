#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		std::string num = ss.str();
		zombies[i].zombieName(name + num);
	}
	return zombies;
}
