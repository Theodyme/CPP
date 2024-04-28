#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

# define YE "\033[33m"
# define GR "\033[36m"
# define WH "\033[0m"

struct Data {
	int entier;
	std::string string;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &src);
		~Serializer();
	public:
		Serializer &operator=(Serializer const &rhs);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
