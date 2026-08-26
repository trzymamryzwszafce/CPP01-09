#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << this->type << " created" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat Copy of " << obj.type << " created" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		std::cout << "Cat " << this->type << " overwritten by " << obj.type << std::endl;
		Animal::operator=(obj);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << this->type << " reduced to atoms" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEEEEEEOOOOOOOOOOWWWWWWWWWWWWW" << std::endl;
}
