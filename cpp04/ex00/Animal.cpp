#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Cat";
	std::cout << this->type << " created" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Copy of " << obj.type << " created" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) : Animal(obj)
{
	if (this != &obj)
	{
		std::cout << this->name << " overwritten by " << obj.type << std::endl;
		Animal::operator=(obj);
	}
	return *this;
}

Cat::~Cat();
{
	std::cout << this->type << " reduced to atoms" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "MEEEEEEOOOOOOOOOOWWWWWWWWWWWWW" << std::endl;
}
