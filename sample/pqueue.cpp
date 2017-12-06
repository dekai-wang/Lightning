#include <iostream>
#include "data_structures/lt_priority_queue.h"

int main()
{
    lt::PriorityQueue<int> qu;

    for (int i = 1; i < 10; i++)
    {
        qu.insert(i);
    }

    int m = qu.erase_min();

    std::cout << m << std::endl;
    return 0;
}
