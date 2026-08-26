#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int	main()
// {
// 	std::cout << "\n--- GOOD ANIMALS ---\n\n";
// 	{
// 		const Animal* meta = new Animal();
// 		const Animal* j = new Dog();
// 		const Animal* i = new Cat();
//
// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;
// 		i->makeSound(); //will output the cat sound!
// 		j->makeSound();
// 		meta->makeSound();
//
// 		delete meta;
// 		delete j;
// 		delete i;
// 	}
// 	std::cout << "\n--- WRONG ANIMALS ---\n\n";
// 	{
// 		const WrongAnimal *meta = new WrongAnimal();
// 		const WrongAnimal *cat = new WrongCat();
//
// 		std::cout << meta->getType() << " " << std::endl;
// 		std::cout << cat->getType() << " " << std::endl;
// 		meta->makeSound();
// 		cat->makeSound();
//
// 		delete meta;
// 		delete cat;
//
// 	}
// 	return 0;
// }

// NOTE: this is a TEST HARNESS, not the exercise solution.
// It only calls your classes' public interface — you still need
// Animal/Dog/Cat/WrongAnimal/WrongCat implemented yourself.
 
void separator(std::string title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}
 
int main()
{
	separator("TEST 1: basic construction + getType()");
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
 
		std::cout << "meta type: " << meta->getType() << std::endl;
		std::cout << "j type: " << j->getType() << std::endl;
		std::cout << "i type: " << i->getType() << std::endl;
 
		delete meta;
		delete j;
		delete i;
	}
 
	separator("TEST 2: virtual dispatch (correct polymorphism)");
	{
		const Animal* animals[3];
		animals[0] = new Animal();
		animals[1] = new Dog();
		animals[2] = new Cat();
 
		for (int k = 0; k < 3; k++)
			animals[k]->makeSound(); // MUST print Animal/Dog/Cat sound respectively
 
		for (int k = 0; k < 3; k++)
			delete animals[k]; // watch destructor order print for each
	}
 
	separator("TEST 3: WrongAnimal (non-virtual) shows broken polymorphism");
	{
		WrongAnimal* wa = new WrongCat();
		wa->makeSound(); // should print WrongAnimal's sound, NOT WrongCat's
		                 // (because makeSound is not virtual in WrongAnimal)
		delete wa;
	}
 
	separator("TEST 4: calling on the real type directly (sanity check)");
	{
		Dog realDog;
		Cat realCat;
		WrongCat realWrongCat;
 
		realDog.makeSound();       // Dog sound
		realCat.makeSound();       // Cat sound
		realWrongCat.makeSound();  // WrongCat sound (direct call, no pointer trickery)
	}
 
	separator("TEST 5: object slicing");
	{
		Dog d;
		Animal sliced = d; // slicing happens here: only the Animal part is copied
		sliced.makeSound(); // prints Animal's sound, NOT Dog's — that's expected!
	}
 
	separator("TEST 6: destructor chain via base pointer");
	{
		std::cout << "About to delete a Dog through an Animal* ..." << std::endl;
		Animal* a = new Dog();
		delete a;
		std::cout << "^ Check: did BOTH ~Dog() and ~Animal() print?" << std::endl;
		std::cout << "  If only ~Animal() printed, your destructor isn't virtual!" << std::endl;
	}
 
	return 0;
}
