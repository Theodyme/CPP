#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	Data *ptr;

	data->entier = 42;
	data->string = "pouet";

	std::cout << GR << "data address: " << WH << data << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << YE << "inside uintptr data address: " << WH << reinterpret_cast<void*>(raw) << std::endl;
	//le cast est la pour afficher l'adresse au bon format (hexa) !!

	ptr = Serializer::deserialize(raw);
	std::cout << GR << "data ptr address: " << WH << ptr << std::endl;

	std::cout << YE << "int : " << WH << data->entier << std::endl;
	std::cout << YE << "string : " << WH << data->string << std::endl;
}
