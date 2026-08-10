#include <iostream>
#include <string>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address: of the string: " << &brain << std::endl;
	std::cout << "Memory address: held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address: held by stringREF: " << &stringREF << "\n\n";

	std::cout << "Value of the string: " << brain << std::endl;
	std::cout << "value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of the stringREF: " << stringREF << std::endl;

	return 0;
}
