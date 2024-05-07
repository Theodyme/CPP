#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(RPN const& src)
{
	(void)src;
}
RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return *this;
}

template<typename T>
T retrieve(std::stack<T> &queue)
{
	T c = queue.top();
	queue.pop();
	return c;
}

void RPN::addition()
{
	double op2 = 0;
	double op1 = 0;

	if (!this->_operands.empty())
		op2 = (retrieve(this->_operands));
	if (!this->_operands.empty())
	{
		op1 = (retrieve(this->_operands));
		// std::cout << op1 << " + " << op2 << std::endl;
		this->_operands.push(op1 + op2);
	}
}

void RPN::soustraction()
{
	double op2;
	double op1;

	if (!this->_operands.empty())
		op2 = (retrieve(this->_operands));
	if (!this->_operands.empty())
	{
		op1 = (retrieve(this->_operands));
		// std::cout << op1 << " - " << op2 << std::endl;
		this->_operands.push(op1 - op2);
	}
}

void RPN::multiplication()
{
	double op2;
	double op1;

	if (!this->_operands.empty())
		op2 = (retrieve(this->_operands));
	if (!this->_operands.empty())
	{
		op1 = (retrieve(this->_operands));
		// std::cout << op1 << " * " << op2 << std::endl;
		this->_operands.push(op1 * op2);
	}
}

void RPN::division()
{
	double op2;
	double op1;

	if (!this->_operands.empty())
		op2 = (retrieve(this->_operands));
	if (!this->_operands.empty())
	{
		op1 = (retrieve(this->_operands));
		// std::cout << op1 << " / " << op2 << std::endl;
		this->_operands.push(op1 / op2);
	}
}

void RPN::calculator(char op)
{

	switch (op)
	{
	case '+':
		addition();
		break;
	case '-':
		soustraction();
		break;
	case '*':
		multiplication();
		break;
	case '/':
		division();
		break;
	default:
		break;
	}
}

bool RPN::queueHandler(char *arg)
{
	if (arg[0] && !std::isdigit(arg[0]))
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	this->_operands.push(arg[0] - '0');
	for (int i = 1; arg[i]; i++)
	{
		if (std::isdigit(arg[i]))
			this->_operands.push(arg[i] - '0');
		else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
		{
			this->calculator(arg[i]);
		}
		else if (arg[i] == ' ')
			continue ;
		else
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
	}
	if (this->_operands.size() == 1)
		std::cout << this->_operands.top() << std::endl;
	else
	{
		std::cout << "Error" << std::endl;
		return false;
	}
	return true;
}
