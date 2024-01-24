#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal	*Pets[8];

	for (int i = 0; i < 4; i++)
		Pets[i] = new Dog();
	for (int i = 4; i < 8; i++)
		Pets[i] = new Cat();
	for (int i = 0; i < 8; i++)
		delete Pets[i];

	std::cout << "-------------------\n\n";
	Dog dog1;
	std::cout << RE << "original dog created\n\n" << WH;
	Dog dog2(dog1); //deep copy
	std::cout << RE << "deep copy created\n\n" << WH;

	std::cout << RE << "Changing idea[1] to ''I have a new owner!!!''\n\n" << WH;
	dog1.getBrain()->setIdea(1, "I have a new owner!!!");
	std::cout << RE << "\noriginal dog:\n" << WH;
	std::cout << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << RE << "\ndeep copy:\n" << WH;
	std::cout << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << dog2.getBrain()->getIdea(1) << std::endl;

	std::cout << "-------------------\n\n";
	Cat cat1;
	std::cout << RE << "original cat created\n\n" << WH;
	Cat cat2(cat1);
	std::cout << RE << "deep copy created\n\n" << WH;

	std::cout << RE << "Changing idea[1] to ''I saw a mouse just now!''\n\n" << WH;
	cat1.getBrain()->setIdea(1, "I saw a mouse just now!");
	std::cout << RE << "\noriginal cat:\n" << WH;
	std::cout << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << cat1.getBrain()->getIdea(1) << std::endl;
	std::cout << RE << "\ndeep copy:\n" << WH;
	std::cout << cat2.getBrain()->getIdea(2) << std::endl;
	std::cout << cat2.getBrain()->getIdea(3) << std::endl;
	std::cout << "-------------------\n\n";
	return (0);
}
