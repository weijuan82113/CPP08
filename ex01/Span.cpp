#include "Span.h"

Span::Span(unsigned int N) : max_size_(N) {};
Span::~Span() {};
Span::Span(const Span& sp) {*this = sp;};
Span& Span::operator=(const Span& sp)
{
	if (this != &sp)
	{
		numbers_ = sp.numbers_;
		max_size_ =sp.max_size_;
	}
	return *this;
};

void Span::addNumber(int number)
{
	if (numbers_.size() >= max_size_ )
		throw std::out_of_range("Cannot add more numbers, Span is full.");
	numbers_.push_back(number);
};

int Span::shortestSpan() const
{
	if (numbers_.size() < 2)
		throw std::logic_error("Cannot find a span in less than 2 numbers.");
	std::vector<int> sorted_numbers = numbers_;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	//compare the interval within the stored numbers;
	int min_span = sorted_numbers[1] - sorted_numbers[0];
	for (size_t i = 1; i < sorted_numbers.size() - 1; i ++)
	{
		int span = sorted_numbers[i + 1] - sorted_numbers[i];
		if (span < min_span)
			min_span = span;
	}
	return min_span;
};

int Span::longestSpan() const
{
	if (numbers_.size() < 2)
		throw std::logic_error("Cannot find a span in less than 2 numbers.");

	//max_span equal the biggest number - smallest number;
	int max_number = *std::max_element(numbers_.begin(), numbers_.end());
	int min_number = *std::min_element(numbers_.begin(), numbers_.end());
	return max_number - min_number;
}

const std::vector<int> Span::getNumbers() const
{
	return numbers_;
}
