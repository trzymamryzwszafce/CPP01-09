#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Kreatura";
	std::cout << this->type << " created" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type)
{
	std::cout << "Animal copy of " << obj.type << " created" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
	{
		std::cout << "Animal " << this->type << " overwritten by " << obj.type << std::endl;
		Animal::operator=(obj);
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor type: " << this->type << " reduced to atoms" << std::endl;
}

std::string	Animal::getType() const
{
	std::string str = "This is " + this->type;
	return (str);
}

void	Animal::makeSound() const
{
	std::cout << "Creature feature" << std::endl;
}
