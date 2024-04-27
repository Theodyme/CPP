#include "ScalarConverter.hpp"

/*                                CONSTRUCTEURS                               */
ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter&src)
{
	(void)src;
}
/*                                DESTRUCTEURS                                */

ScalarConverter::~ScalarConverter()
{

}
/*                              OPERATOR OVERLOAD                             */

/*                                   METHODS                                  */
void ScalarConverter::convert(const std::string arg)
{
	std::string trimmed = arg;


	for (size_t i = 0; i < trimmed.size(); i++)
	{
		if (std::isspace(trimmed[i])) 
		{
			trimmed.erase(i, 1);
			--i;
		}
	}
	if (!trimmed[0])
	{
		std::cout << "Nothing to convert!\n";
		return ;
	}
	// std::cout << "trimmed: " << trimmed << "\n";
	char *last;

	int intType = strtol(trimmed.c_str(), &last, 10);
	if (last)
	{
		
	}




	return;
}
