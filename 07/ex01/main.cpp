#include "iter.hpp"

template <typename T>
void	sayCheese(T var)
{
	std::cout << "cheese " << var << std::endl;
}

void	add1(int &i)
{
	i++;
}

void	upcaseStr(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		s[i] = std::toupper(s[i]);
	}
}

int	main(void)
{
	int	intArr[] = {1, 2, 3, 4, 5};
	std::string strArr[] = {"hello", "hi", "aaa", "bbb", "cccc"};

	iter<int>(intArr, 5, &add1);
	iter<std::string>(strArr, 5, &upcaseStr);

	for (int i = 0; i < 5; i++)
		std::cout << intArr[i] << std::endl;

	std::cout << std::endl;
	
	for (int i = 0; i < 5; i++)
		std::cout << strArr[i] << std::endl;

	std::cout << std::endl;

	iter<int>(intArr, 5, &sayCheese);
	
	std::cout << std::endl;
}