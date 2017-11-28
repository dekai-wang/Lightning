#include <iostream>
#include "data_structures/lt_stack.h"

int main()
{
    lt::Stack<int> stacks;

    for (int i = 1; i < 10; i++)
        stacks.push(i);

    std::cout << stacks.size() << std::endl;

    for (int i = 1; i < 9; i++)
    {
        std::cout << stacks.pop() << std::endl;
    }

    std::cout << stacks.size() << std::endl;

    return 0;
}
