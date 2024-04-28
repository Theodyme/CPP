#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cerrno>
# include <cstring>
# include <cstdlib>
# include <cctype>
# include <climits>
# include <cfloat>

# define RE "\033[31m"
# define WH "\033[0m"
# define PU "\033[35m"

enum Type {
	INT, // 0
	DOUBLE, // 1
	FLOAT, // 2
	CHAR, // 3
	UNDISPLAYABLE, // 4
	INVALID // 5
};

class ScalarConverter
{
	private:
		std::string _trarg;
		Type _type;
		long int	_int;
		double _double;
		float _float;
		char _char;

		ScalarConverter();
		ScalarConverter(const ScalarConverter&src);
		~ScalarConverter();
	public:
		ScalarConverter	&operator=(ScalarConverter const &rhs);
		int	trimming(void);
		void firstCheck(void);
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
		void printer(Type type);
		static void convert(const std::string arg);

	class Overflow : public std::exception
	{
		public:
			virtual const char* what() const throw();

	};
};

# endif
