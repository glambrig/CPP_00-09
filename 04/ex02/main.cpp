#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog		dogs[2];
	Cat		cats[2];
	// Animal	test; // causes error

	for (int i = 0; i < 2; i++)
	{
		dogs[i].makeSound();
		cats[i].makeSound();
	}
	return 0;
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }