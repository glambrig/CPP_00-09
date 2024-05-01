#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	Animal	arr[4];

// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (i < 5)
// 			arr[i] = Cat();
// 		else
// 			arr[i] = Dog();
// 		arr[i].makeSound();
// 	}
// 	return 0;
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	return 0;
}