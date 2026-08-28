#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n--- GIVEN MAIN ---\n\n";
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;
	}
	std::cout << "\n--- 10 ANIMALS ---\n\n";
	{
		const Animal *animals[10];
		std::cout << "\n ----- dogs ------\n" << std::endl;
		for (int i = 0; i < 5; i++)
			animals[i] = new Dog();
		std::cout << " ----- cats ------\n" << std::endl;
		for (int i = 5; i < 10; i++)
			animals[i] = new Cat();
		for (int i = 0; i < 10; i++)
			animals[i]->makeSound();
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << "\n--- DEEP COPY ---\n\n";
	{
		Cat cat1;
		cat1.setIdea("fih");

		Cat cat2(cat1);

		std::cout << "\n---before modyfing---\n\n";
		cat1.getIdea();
		cat2.getIdea();
		
		std::cout << "\n---after modyfing===\n\n";
		cat2.setIdea("more fih");
		cat1.getIdea();
		cat2.getIdea();
		std::cout << "\n";
	}
	std::cout << "\n--- DEEP COPY (COPY ASSIGNMENT) ---\n\n";
	{
		Dog dog1;
		Dog dog2;
		dog1.setIdea("biscuit");

		dog2 = dog1;

		std::cout << "\n---before modyfing---\n\n";
		dog1.getIdea();
		dog2.getIdea();
		
		std::cout << "\n---after modyfing===\n\n";
		dog2.setIdea("more biscuit");
		dog1.getIdea();
		dog2.getIdea();
		std::cout << "\n";
	}
	return 0;
}
