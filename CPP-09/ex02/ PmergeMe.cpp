#include "PmergeMe.hpp"

template<typename T>
T &mergeInsertSort(T &container)
{
	T<std::pair<int, int>> divided;
	typedef typename T::iterator Iterator;

	for (Iterator it = container.begin(); (it != container.end()) && ((it + 1) != container.end()); it += 2)
	{
		std::pair<int, int> pair = std::make_pair(*it, *(it + 1));
		divided.push_back(pair);
	}

	return ;
}
