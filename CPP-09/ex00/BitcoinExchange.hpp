#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> _data;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		void trimming(std::string totrim);
};

#endif