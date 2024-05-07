#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cctype>
#include <queue>
#include <stack>

class RPN
{
	private:
		std::stack<double> _operands;
	public:
		RPN();
		RPN(RPN const& src);
		~RPN();

		RPN &operator=(RPN const &rhs);
		void addition();
		void soustraction();
		void multiplication();
		void division();
		void calculator(char op);
		bool queueHandler(char *arg);
};

#endif
