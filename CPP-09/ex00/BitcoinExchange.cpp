#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::fstream fs("data.csv");
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
	for (std::map<std::string, std::string>::iterator it = this->_data.begin(); it != this->_data.end(); it++)
	{
		std::cout << it->first << " : " << it->second << std::endl; 
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
		if (std::isspace(totrim[i]) == true)
		{
			totrim.erase(i, 1);
			--i;
		}
	}
	return ;
}