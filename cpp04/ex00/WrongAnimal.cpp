#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Kreatura";
	std::cout << this->type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type)
{
	std::cout << "Animal copy of " << obj.type << " created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
	{
		std::cout << "Animal " << this->type << " overwritten by " << obj.type << std::endl;
		WrongAnimal::operator=(obj);
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor type: " << this->type << " reduced to atoms" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	std::string str = "This is " + this->type;
	return (str);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Creature feature" << std::endl;
}
