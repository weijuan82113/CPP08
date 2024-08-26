#include <iostream>
#include "MutantStack.h"

// Test code
int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    int cout = 0;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
        cout ++;
    }
    std::cout << "------test stack(mutant copy)------" << std::endl;
    std::stack<int> s(mstack);
    for (int i = 0; i < cout; i ++)
    {
        std::cout << s.top() << std::endl;s.pop();
    }
    std::cout << "------test stack(mutant copy)------" << std::endl;
    return 0;
}