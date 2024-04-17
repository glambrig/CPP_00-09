#include <iostream>
#include <string>
#include <fstream>

std::string	replace(char *str, int len, std::string &s1, std::string &s2)
{
	std::string s = str;
	size_t		pos;

	for (int i = 0; i < len; i++)
	{
		if (s.find(s1) != (long unsigned int)-1)
		{
			pos = s.find(s1);
			s.erase(pos, s1.length());
			s.insert(pos, s2);
		}
	}
	return (s);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		return (std::cout << "Too many/not enough arguments"
			<< std::endl, 0);
	}
	std::string	s1 = av[2], s2 = av[3], filename = av[1];
	std::fstream file;
	std::fstream newFile;

	file.open(filename.c_str());
	/*I have to open it in out mode first, so that the file is created
		if it doesn't exist (which will always be true).
		This is like calling open() in C with O_CREAT flag*/
	newFile.open((filename + ".replace").c_str(), std::ios::out);
	newFile << '\0';
	newFile.close();
	newFile.open((filename + ".replace").c_str());

	/*Gets file length*/
	file.seekg(0, file.end);//Sets get pointer (where we are in the file) to the end
	int len = file.tellg();//Returns the position of the get pointer
	file.seekg(0, file.beg);//Sets get pointer back to the beginning

	char *buff = new char[len + 1];
	file.read(buff, len);
	buff[len] = '\0';
	newFile << replace(buff, len, s1, s2);

	file.close();
	newFile.close();
	delete[] buff;
	return (0);
}