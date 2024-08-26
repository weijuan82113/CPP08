#include <iostream>
#include <deque>
#include "MutantStack.h"

// Test code
int main() {
    std::stack<int, std::deque<int> > mstack;
    std::cout << "push: 5 \n";
    mstack.push(5);
    std::cout << "push: 17 \n";
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "pop \n";
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    std::cout << "push: 3 \n";
    mstack.push(3);
    std::cout << "push: 5 \n";
    mstack.push(5);
    std::cout << "push: 737 \n";
    mstack.push(737);
    std::cout << "push: 0 \n";
    mstack.push(0);

    MutantStack<int, std::deque<int> >::iterator it = mstack.begin();
    MutantStack<int, std::deque<int> >::iterator ite = mstack.end();
    ++it;
    --it;
    int count = 0;
    std::cout << "-----mutant stack(print by iterator)----- \n";
    std::cout << "-----front-----" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        it ++;
        count ++;
    }
    std::cout << "-----back-----" << std::endl;
    std::cout << "-----mutant stack(print by iterator)-----\n\n" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "-----mutant_stack(copy)-----" << std::endl;
    std::cout << "-----top-----" << std::endl;
    for (int i = 0; i < count; i ++)
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << "-----bottom-----" << std::endl;
    std::cout << "------mutant_stack(copy)------" << std::endl;
    return 0;
}