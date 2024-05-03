#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top of the stack (expecting 17)" << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << "pop the top of the stack (17)" << std::endl;
	mstack.pop();
	std::cout << "size of the stack (expecting 1)" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "top of the stack (expecting 5)" << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "parsing the stack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
