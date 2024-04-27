#include "ScalarConverter.hpp"

/*                                CONSTRUCTEURS                               */
ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter&src)
{
	(void)src;
}
/*                                DESTRUCTEURS                                */

ScalarConverter::~ScalarConverter() { }

/*                              OPERATOR OVERLOAD                             */

/*                                   METHODS                                  */

int	ScalarConverter::trimming(void)
{
	for (size_t i = 0; i < this->_trarg.size(); i++)
	{
		if (std::isspace(this->_trarg[i]) == true)
		{
			this->_trarg.erase(i, 1);
			--i;
		}
	}
	if (!_trarg[0])
	{
		std::cout << "Nothing to convert!\n";
		return 1;
	}
	return 0;
}

void ScalarConverter::firstCheck(void)
{
	char *suffix;

	if (this->_trarg.size() == 1)
	{
		if (isdigit(this->_trarg[0]) == false)
		{
			this->_char = this->_trarg[0];
			this->_type = CHAR;
			return ;
		}
	}

	try
	{
		this->_int = strtol(this->_trarg.c_str(), &suffix, 10);
		if (errno == ERANGE || this->_int > INT_MAX || this->_int < INT_MIN)
			throw ScalarConverter::Overflow();
		if (suffix[0])
		{
			this->_double = strtod(this->_trarg.c_str(), &suffix);
			if (errno == ERANGE)
				throw ScalarConverter::Overflow();
			if (suffix[0])
			{
				this->_float = strtof(this->_trarg.c_str(), &suffix);
				if (errno == ERANGE)
					throw ScalarConverter::Overflow();
				if (strcmp(suffix, "f"))
					this->_type = INVALID;
				else
					this->_type = FLOAT;
			}
			else
				this->_type = DOUBLE;
			return ;
		}
		this->_type = INT;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

void ScalarConverter::printChar()
{
		std::cout << PU << "Char: " << WH;
		std::cout << this->_char << std::endl;
		std::cout << PU << "Int: " << WH;
		std::cout << static_cast<int>(this->_char) << std::endl;
		std::cout << PU << "Float: " << WH;
		std::cout << static_cast<float>(this->_char) << "f" << std::endl;
		std::cout << PU << "Double: " << WH;
		std::cout << static_cast<double>(this->_char) << std::endl;
}

void ScalarConverter::printInt()
{
	std::cout << PU << "Char: " << WH;
	if (this->_int >= 0 && this->_int <= 255 && isprint(this->_int))
		std::cout << static_cast<char>(this->_int) << std::endl;
	else
		std::cout << "non displayable.\n";
	std::cout << PU << "Int: " << WH;
	std::cout << this->_int << std::endl;
	std::cout << PU << "Float: " << WH;
	std::cout << static_cast<float>(this->_int) << "f" << std::endl;
	std::cout << PU << "Double: " << WH;
	std::cout << static_cast<double>(this->_int) << std::endl;
}

void ScalarConverter::printFloat()
{
	std::cout << PU << "Char: " << WH;
	if (this->_float >= 0 && this->_float <= 255 && isprint(this->_float))
		std::cout << static_cast<char>(this->_float) << std::endl;
	else
		std::cout << "non displayable.\n";
	std::cout << PU << "Int: " << WH;
	if (this->_float >= static_cast<float>(INT_MIN) && this->_float <= static_cast<float>(INT_MAX))
		std::cout << static_cast<int>(this->_float) << std::endl;
	else
		std::cout << "impossible.\n";
	std::cout << PU << "Float: " << WH;
	std::cout << this->_float << "f" << std::endl;
	std::cout << PU << "Double: " << WH;
	std::cout << static_cast<double>(this->_float) << std::endl;
}

void ScalarConverter::printDouble()
{
	std::cout << PU << "Char: " << WH;
	if (this->_double >= 0 && this->_double <= 255 && isprint(this->_double))
		std::cout << static_cast<char>(this->_double) << std::endl;
	else
		std::cout << "non displayable.\n";
	std::cout << PU << "Int: " << WH;
	if (this->_double >= INT_MIN && this->_double <= INT_MAX)
		std::cout << static_cast<int>(this->_double) << std::endl;
	else
		std::cout << "impossible.\n";
	std::cout << PU << "Float: " << WH;
	if (this->_double >= FLT_MIN && this->_double <= FLT_MAX)
		std::cout << static_cast<float>(this->_double) << "f" << std::endl;
	else
		std::cout << "impossible.\n";
	std::cout << PU << "Double: " << WH;
	std::cout << this->_double << std::endl;
}

void ScalarConverter::printer(Type type)
{
	switch (type)
	{
	case CHAR:
		this->printChar();
		break;

	case INT:
		this->printInt();
		break;

	case FLOAT:
		this->printFloat();
		break;

	case DOUBLE:
		this->printDouble();
		break;

	default:
		break;
	}
}

void ScalarConverter::convert(const std::string arg)
{
	ScalarConverter converter;

	converter._trarg = arg;
	if (converter.trimming() == 1)
		return;
	converter.firstCheck();
	if (converter._type == INVALID)
	{
		std::cout << RE << "Error:" << WH << " invalid input\n";
		return ;
	}
	std::cout << std::showpoint << std::setprecision(5);
	converter.printer(converter._type);
	return;
}

const char* ScalarConverter::Overflow::what() const throw()
{
	return RE "Error:" WH " overflow";
}
