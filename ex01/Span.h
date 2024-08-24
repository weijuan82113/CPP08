#ifndef SPAN_H_
 #define SPAN_H_

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
	public:
		Span(const unsigned int N);
		~Span();
		Span(const Span& sp);
		Span& operator=(const Span& sp);
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		const std::vector<int> getNumbers() const;
		template <typename T>
		void addNumbers(T begin, T end);

	private:
		Span();
		std::vector<int> numbers_;
		unsigned int max_size_;
};

template <typename T>
void Span::addNumbers(T begin, T end)
{
	while (begin != end)
	{
		if (numbers_.size() >= max_size_)
			throw std::out_of_range("Cannot add more numbers, Span is full.");
		numbers_.push_back(*begin);
		++begin;
	}
};

#endif