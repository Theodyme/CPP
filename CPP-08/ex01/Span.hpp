#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <algorithm>
# include <vector>

class Span
{
	private:
		std::vector<int> _values;
		unsigned int _max;
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();
		Span &operator=(Span const &rhs);

		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};


#endif
