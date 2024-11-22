#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <utility>
#include <ctime>

// Suite de Jacobsthal en dur
const int jacobsthalIndices[] = {
	0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845,
	43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811,
	22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765
};

// Taille de la suite de Jacobsthal
const size_t jacobsthalSize = sizeof(jacobsthalIndices) / sizeof(jacobsthalIndices[0]);

template <typename C>
void	printList(C &container)
{
	std::cout << "[";
	for (size_t i = 0; i < container.size(); i++)
	{	
		std::cout << container[i];
		if ((i + 1) != container.size())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename C>
void	print(C &container, std::string type)
{
	if (type == "VECTOR")
		std::cout << "vector: ";
	else
		std::cout << "deque: ";
	printList(container);
}

template <typename C>
int		fill(char **av, C &container)
{
	char *suffix;
	for (int i = 1; av[i]; i++)
	{
		long value = strtol(av[i], &suffix, 10);
		if (*suffix != '\0' || value <= 0)
		{
			std::cerr << "Error: invalid argument\n";
			return 1;
		}
		container.push_back(value);
	}
	return 0;
}

template <typename T>
std::pair<T, T>	sortPair(T &a, T &b)
{
	return	(a > b) ? std::make_pair(a, b) : std::make_pair(b, a);
}

template <typename T, typename C>
void	binarySearch(C& list, T element) {
	typename C::iterator it = std::lower_bound(list.begin(), list.end(), element);
	list.insert(it, element);
}


//////////////////////// SORT VECTOR //////////////////////////

template <typename T>
std::vector<T> sortVector(std::vector<T> &initialList)
{
	if (initialList.size() <= 1)
		return initialList;

	std::vector<std::pair<T, T> >	paired;

	for (size_t i = 0; i < initialList.size(); i += 2)
	{
		if ((i + 1) < initialList.size())
			paired.push_back(sortPair(initialList[i], initialList[i + 1]));
		else
			paired.push_back(std::pair<T, T>(initialList[i], T()));
	}
	
	// creation d'une liste temporaire contenant les plus grands elem. de chaque paire
	std::vector<T> largerList;
	for (size_t i = 0; i < paired.size(); i++)
	{
		largerList.push_back(paired[i].first);
	}

	// recursion dans le sort des elements les + grands
	std::vector<T> sortedList = sortVector(largerList);
	std::vector<bool>	isInserted(paired.size(), false);

	// insertion des éléments appairés selon les indices de jacobsthal
	for (size_t i = 0; i < jacobsthalSize; i++)
	{
		size_t idx = static_cast<size_t>(jacobsthalIndices[i]);
		if (idx >= paired.size())
		{
			for (size_t newIdx = jacobsthalIndices[i - 1]; newIdx < paired.size(); newIdx++)
			{
				if (paired[newIdx].second != T() && !isInserted[newIdx])
				{
					binarySearch(sortedList, paired[newIdx].second);
					isInserted[newIdx] = true;
				}
			}
			break ;
		}
		if (paired[idx].second != T() && !isInserted[idx])
		{
			binarySearch(sortedList, paired[idx].second);
			isInserted[idx] = true;
		}

		// fonction pour backtrack
		if (i > 0)
		{
			for (size_t prevIdx = jacobsthalIndices[i - 1]; prevIdx < idx; prevIdx++)
			{
				if (paired[prevIdx].second != T() && !isInserted[prevIdx])
				{
					binarySearch(sortedList, paired[prevIdx].second);
					isInserted[prevIdx] = true;
				}
			}
		}
	}
	return sortedList;
}



//////////////////////// SORT DEQUE //////////////////////////

template <typename T>
std::deque<T> sortDeque(std::deque<T> &initialList)
{
	if (initialList.size() <= 1)
		return initialList;

	std::deque<std::pair<T, T> >	paired;

	for (size_t i = 0; i < initialList.size(); i += 2)
	{
		if ((i + 1) < initialList.size())
			paired.push_back(sortPair(initialList[i], initialList[i + 1]));
		else
			paired.push_back(std::pair<T, T>(initialList[i], T()));
	}
	
	// creation d'une liste temporaire contenant les plus grands elem. de chaque paire
	std::deque<T> largerList;
	for (size_t i = 0; i < paired.size(); i++)
	{
		largerList.push_back(paired[i].first);
	}

	// recursion dans le sort des elements les + grands
	std::deque<T> sortedList = sortDeque(largerList);
	std::deque<bool>	isInserted(paired.size(), false);

	// insertion des éléments appairés selon les indices de jacobsthal
	for (size_t i = 0; i < jacobsthalSize; i++)
	{
		size_t idx = static_cast<size_t>(jacobsthalIndices[i]);
		if (idx >= paired.size())
		{
			for (size_t newIdx = jacobsthalIndices[i - 1]; newIdx < paired.size(); newIdx++)
			{
				if (paired[newIdx].second != T() && !isInserted[newIdx])
				{
					binarySearch(sortedList, paired[newIdx].second);
					isInserted[newIdx] = true;
				}
			}
			break ;
		}
		if (paired[idx].second != T() && !isInserted[idx])
		{
			binarySearch(sortedList, paired[idx].second);
			isInserted[idx] = true;
		}

		// fonction pour backtrack
		if (i > 0)
		{
			for (size_t prevIdx = jacobsthalIndices[i - 1]; prevIdx < idx; prevIdx++)
			{
				if (paired[prevIdx].second != T() && !isInserted[prevIdx])
				{
					binarySearch(sortedList, paired[prevIdx].second);
					isInserted[prevIdx] = true;
				}
			}
		}
	}
	return sortedList;
}