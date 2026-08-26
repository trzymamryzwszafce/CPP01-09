#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "\n--- GOOD ANIMALS ---\n\n";
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "\n--- WRONG ANIMALS ---\n\n";
	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *cat = new WrongCat();

		std::cout << meta->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		meta->makeSound();
		cat->makeSound();

		delete meta;
		delete cat;
	}
	std::cout << "\n--- STACK ALLOCATION --- \n\n";
	{
		Animal animal;
		Cat cat;
		Dog dog;

		std::cout << animal.getType() << " " << std::endl;
		std::cout << cat.getType() << " " << std::endl;
		std::cout << dog.getType() << " " << std::endl;

		animal.makeSound();
		cat.makeSound();
		dog.makeSound();
	}
	return 0;
}
