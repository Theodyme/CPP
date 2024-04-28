#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	std::srand(std::time(0));
	int random = std::rand() % 3;

	std::cout << random << std::endl;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	if (a)
		std::cout << RE << "A" << WH << std::endl;
	else if (b)
		std::cout << BL << "B" << WH << std::endl;
	else if (c)
		std::cout << YE << "C" << WH << std::endl;
	else
		std::cout << GR << "Base type" << WH << std::endl << std::endl;
}

void identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << RE << "A" << WH << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		try
		{
			B&	b = dynamic_cast<B&>(p);
			std::cout << BL << "B" << WH << std::endl;
			(void)b;
		}
		catch(const std::exception& e)
		{
			try
			{
				C&	c = dynamic_cast<C&>(p);
				std::cout << YE << "C" << WH << std::endl;
				(void)c;
			}
			catch(const std::exception& e)
			{ }
		}
	}
}

int main()
{
	Base *ptr = new Base;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
}
