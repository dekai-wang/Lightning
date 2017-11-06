#include <iostream>
#include "data_structures/lt_list.h"

int main()
{
    lt::LinkList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    //list.insert_after(7, 3);
    //list.insert_after(8, 4);
    //list.erase(4, 5);

    for (int i = 0; i < list.size() + 1; i++)
        std::cout << list.get(i) << std::endl;
    list.reverse();

    for (int i = 0; i < list.size() + 1; i++)
        std::cout << list.get(i) << std::endl;




    return 0;
}
