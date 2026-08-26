#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << this->type << " created" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog copy of " << obj.type << " created" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		std::cout << "Dog " << this->type << " overwritten by " << obj.type << std::endl;
		Animal::operator=(obj);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << this->type << " reduced to atoms" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WOOOF" << std::endl;
}
