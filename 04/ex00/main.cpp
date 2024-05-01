#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl << std::endl;

	Animal	a;
	Cat		cat;
	Dog		dog;
	std::cout << std::endl << std::endl;
	std::cout << "a type = " << a.getType() << std::endl;
	std::cout << "cat type = " << cat.getType() << std::endl;
	std::cout << "dog type = " << dog.getType() << std::endl;
	std::cout << std::endl;
	a.makeSound();
	dog.Animal::makeSound();
	cat.Animal::makeSound();
	std::cout << std::endl;

	return 0;
}