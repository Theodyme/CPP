#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\n";
	std::cout << "---------------\n";
	std::cout << "\n";
	std::cout << j->getType() << " : ";
	j->makeSound(); //dog sound
	std::cout << i->getType() << " : ";
	i->makeSound(); //will output the cat sound!
	std::cout << "\n";
	std::cout << meta->getType() << " : ";
	meta->makeSound();
	std::cout << "\n";
	std::cout << "---------------\n";
	std::cout << "\n";
	delete meta;
	delete i;
	delete j;
	std::cout << "\n";
	std::cout << "---------------\n";
	std::cout << "\n";
	const WrongAnimal *y = new WrongAnimal();
	const WrongAnimal *z = new WrongCat();
	std::cout << "\n";

	std::cout << y->getType() << " : ";
	y->makeSound();
	std::cout << z->getType() << " : ";
	z->makeSound();// makes animal sound because this time makeSound isn t virtual

	std::cout << "\n";
	delete y;
	delete z;

	return (0);
}
