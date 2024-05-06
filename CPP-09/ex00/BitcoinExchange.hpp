#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> _data;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		void trimming(std::string totrim);
		bool date_checker(std::string date);
		bool value_checker(std::string value);	
		void file_handler(char *filename);
};

#endif