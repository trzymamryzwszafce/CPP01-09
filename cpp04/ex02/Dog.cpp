#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << this->type << " created" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	this->brain = new Brain(*obj.brain);
	std::cout << "Dog copy of " << obj.type << " created" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		delete this->brain;
		std::cout << "Dog " << this->type << " overwritten by " << obj.type << std::endl;
		this->brain = new Brain(*obj.brain);
		Animal::operator=(obj);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << this->type << " reduced to atoms" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WOOOF" << std::endl;
}

void	Dog::setIdea(const std::string& idea)
{
	this->brain->setIdea(idea);
}

void	Dog::getIdea()
{
	std::cout << this->brain->getIdea() << std::endl;
}
