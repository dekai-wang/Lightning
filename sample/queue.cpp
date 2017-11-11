#include <iostream>
#include "data_structures/lt_queue.h"

int main()
{
    lt::Queue<int> Queues;
    Queues.enqueue(1);
    Queues.enqueue(2);
    Queues.enqueue(3);

    size_t size = Queues.size();
    for (auto i = 0; i < size; ++i)
    {
        auto element = Queues.dequeue();
        std::cout << i << " " <<  element << std::endl;
    }

    return 0;
}
