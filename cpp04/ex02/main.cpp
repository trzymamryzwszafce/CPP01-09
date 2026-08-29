#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
// NOTE: won't work cause Animal is an abstract class

//	Animal *animal = new Animal();
//	Animal animal;	same;

	Animal *animal = new Cat();
	std::cout << animal->getType() << std::endl;
	animal->makeSound();

	delete animal;
}
