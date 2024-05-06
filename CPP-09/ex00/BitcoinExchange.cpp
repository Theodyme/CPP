#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::fstream fs("oneline.txt");
	std::string line;

	std::getline(fs, line);
	while (std::getline(fs, line))
	{
		std::string date = line.substr(0, line.find(','));
		std::string value = line.substr(line.find(',') + 1, line.size());
		this->trimming(date);
		this->trimming(value);
		this->_data[date] = value;
	}
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	(void)src;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::trimming(std::string totrim)
{
	for (size_t i = 0; i < totrim.size(); i++)
	{
		if (std::isspace(totrim[i]) == true || std::isprint(totrim[i]) == false)
		{
			totrim.erase(i, 1);
			--i;
		}
	}
	return ;
}

bool BitcoinExchange::date_checker(std::string date)
{
	if (date.size() != 10)
		return false;
	int year, month, day;
	char* suffix;
	year = strtol(date.c_str(), &suffix, 10);
	month = strtol((suffix + 1), &suffix, 10);
	day = strtol((suffix + 1), &suffix, 10);
	// std::cout << year << "-" << month << "-" << day << std::endl;
	if ((year < 2024 && year > 0) && (month < 12 && month > 0) && (day < 31 && day > 0))
		return true;
	std::cout << "Error: bad input => " << date << std::endl;
	return false;
}
bool BitcoinExchange::value_checker(std::string value)
{
	double dvalue;
	char *suffix;

	dvalue = strtod(value.c_str(), &suffix);
	if (suffix[0])
	{
		std::cerr << "Error: invalid input => " << value << std::endl;
		return false;
	}
	if (dvalue < 0.0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	if (dvalue > 1000.0)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}
void BitcoinExchange::file_handler(char *filename)
{
	if (this->_data.empty())
	{
		std::cerr << "Error: no reference to use." << std::endl;
		return ;
	}
	std::fstream fs(filename);
	std::string line;

	std::getline(fs, line);
	while (std::getline(fs, line))
	{
		size_t delim = line.find(" | ");
		if (delim == std::string::npos)
		{
			this->trimming(line);
			this->date_checker(line);
			continue ;
		}
		std::string date = line.substr(0, delim);
		std::string value = line.substr(delim + 3, line.size());
		this->trimming(date);
		this->trimming(value);
		if (this->date_checker(date) == true)
		{
			std::map<std::string, std::string>::iterator it = this->_data.find(date);
			if (it == this->_data.end())
			{
				it = this->_data.lower_bound(date);
				if (it != this->_data.begin())
					it--;
			}
			if (this->value_checker(value) == true)
			{
				char* suffix;
				double dvalue = strtod(value.c_str(), &suffix);
				double dprice = strtod(it->second.c_str(), &suffix);
				std::cout << date << " => " << value << " = " << (dvalue * dprice) << std::endl;	
			}
		}
	}
}