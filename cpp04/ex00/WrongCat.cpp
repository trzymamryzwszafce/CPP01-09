#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "Wrong Cat";
	std::cout << this->type << " created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout << "Cat Copy of " << obj.type << " created" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
	{
		std::cout << "Cat " << this->type << " overwritten by " << obj.type << std::endl;
		WrongAnimal::operator=(obj);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " reduced to atoms" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong MEEEEEEOOOOOOOOOOWWWWWWWWWWWWW" << std::endl;
}
