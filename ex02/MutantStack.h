#ifndef MUTANTSTACK_H_
 #define MUTANTSTACK_H_

#include <stack>
#include <deque>

//Can declare Mutanttack<int, std::list<int>> st; but default is std::deque<T>
//so Mutanttack<int> is use std::deque<T> for underlying base
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	/// Default constructor
	MutantStack() : std::stack<T, Container>() {};
	// Constructor with container
	explicit MutantStack(const Container& cont) : std::stack<T, Container>(cont) {};
	// Copy constructor
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {};
	// Assignment operator
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    };

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif