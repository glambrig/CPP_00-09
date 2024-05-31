#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> arr;

	// for (int i = 0; i < 10; i++)
	// 	arr.push_back(i);

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);

    try
	{
        typename std::vector<int>::iterator result = easyfind<std::vector<int> >(arr, 3);
        std::cout << "Found at position: " << result - arr.begin() << std::endl;
    }
	catch (const char* exception)
	{
        std::cout << "Exception: " << exception << std::endl;
    }

    try
	{
        typename std::vector<int>::iterator result = easyfind<std::vector<int> >(arr, 6);
        std::cout << "Found at position: " << result - arr.begin() << std::endl;
    }
	catch (const char* exception)
	{
        std::cout << "Exception: " << exception << std::endl;
    }
    return 0;
}