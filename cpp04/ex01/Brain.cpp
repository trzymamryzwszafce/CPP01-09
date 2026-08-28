#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default brain created" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Copy of Brain created" << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
		std::cout << "Copy Assignment of brain used" << std::endl;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain reduced to atoms" << std::endl;
}

void	Brain::setIdea(const std::string& idea)
{
	this->ideas[0] = idea;
}

std::string	Brain::getIdea()
{
	return (this->ideas[0]);
}
