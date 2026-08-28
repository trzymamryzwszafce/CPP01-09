#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << this->type << " created" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	this->brain = new Brain(*obj.brain);
	std::cout << "Cat Copy of " << obj.type << " created" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		delete this->brain;
		std::cout << "Cat " << this->type << " overwritten by " << obj.type << std::endl;
		this->brain = new Brain(*obj.brain);
		Animal::operator=(obj);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << this->type << " reduced to atoms" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEEEEEEOOOOOOOOOOWWWWWWWWWWWWW" << std::endl;
}

void	Cat::setIdea(const std::string& idea)
{
	this->brain->setIdea(idea);
}

void	Cat::getIdea()
{
	std::cout << this->brain->getIdea() << std::endl;
}
