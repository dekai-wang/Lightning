#include <iostream>
#include "data_structures/lt_queue.h"

int main()
{
    lt::Queue<int> Queues;
    Queues.enqueue(1);
    Queues.enqueue(3);
    Queues.enqueue(2);

    size_t size = Queues.size();
    std::cout << size << std::endl;
    for (int i = 0; i < size; ++i)
    {
        int element = Queues.dequeue();
        std::cout << i << " " <<  element << std::endl;
    }
    size = Queues.size();
    std::cout << size << std::endl;

    return 0;
}
