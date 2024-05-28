#include "easyfind.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    try
	{
        int *result = easyfind<int>(arr, 3);
        std::cout << "Found at position: " << *result << std::endl;
    }
	catch (const char* exception)
	{
        std::cout << "Exception: " << exception << std::endl;
    }

    try
	{
        int *result = easyfind<int>(arr, 6);
        std::cout << "Found at position: " << *result << std::endl;
    }
	catch (const char* exception)
	{
        std::cout << "Exception: " << exception << std::endl;
    }
    return 0;
}