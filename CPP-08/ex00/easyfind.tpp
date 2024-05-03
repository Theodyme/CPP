#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template<typename T>
void easyfind(T &hay, const int needle)
{
	typename T::iterator it = std::find(hay.begin(), hay.end(), needle);
	if (it == hay.end())
		throw std::out_of_range("out of bounds\n");
	std::cout << "found needle at position " << std::distance(hay.begin(), it) << std::endl;
	return ;
}
#endif
