#include "Replace.hpp"

int	ftReplace(std::string filename, std::string s1, std::string s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cout << "s1 is empty" << std::endl;
		return 1;
	}
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "file cannot open" << std::endl;
		return 1;
	}
	size_t	i;
	std::string	line;
	std::ofstream newfile((filename + ".replace").c_str());
	while (getline(file, line))
	{
		while ((i = line.find(s1)) != std::string::npos)
			line = line.substr(0, i) + s2 + line.substr(i + s1.length());
		newfile << line << std::endl;
	}
	file.close();
	newfile.close();
	return (0);
}
