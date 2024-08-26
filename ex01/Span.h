#ifndef SPAN_H_
 #define SPAN_H_

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
	public:
		Span(const unsigned int N);
		~Span();
		Span(const Span& sp);
		Span& operator=(const Span& sp);
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		const std::vector<int> getNumbers() const;
		template <typename T>
		void addNumbers(T begin, T end);

	private:
		Span();
		std::vector<int> numbers_;
		unsigned int max_size_;
		static void swap(int& x, int& y);
		// unsigned getSpan(int a, intb)をつくる　span > INT_MAXの考慮をする
		static unsigned int getSpan(int x, int y);
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