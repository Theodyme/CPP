#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>

class ScalarConverter
{
	private:
	// CONSTRUCTEURS
		ScalarConverter();
		ScalarConverter(const ScalarConverter&src);
	public:
	// DESTRUCTEURS
		~ScalarConverter();
	// OPERATOR OVERLOAD
	// METHODS
		static void convert(const std::string arg); 
};

# endif
