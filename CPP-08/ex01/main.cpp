#include "Span.hpp"

int main(void)
{
	try
	{
		Span *span = new Span(6);
		Span *span2 = new Span(1);

		span2->addNumber(62);
		// std::cout << "longest span is: " << span->longestSpan() << std::endl;
		// std::cout << "shortest span is: " << span->shortestSpan() << std::endl;

		std::cout << "///////////////////////////////" << std::endl;

		span->addNumber(62);
		span->addNumber(3);
		span->addNumber(6);
		span->addNumber(42);
		span->addNumber(12);
		span->addNumber(-2);
		// span->addNumber(-4);
		std::cout << "longest span is: " << span->longestSpan() << std::endl;
		std::cout << "shortest span is: " << span->shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;

}
