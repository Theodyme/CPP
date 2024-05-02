#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
void easyfind(const T &hay, const int &needle)
{
	typename T::iterator it = std::find(hay.begin(), hay.end(), needle);
	if (it == hay.end())
		throw std::out_of_range
	std::cout << "found needle at position " << it << std::endl;
	return ;
}
#endif
