#include <iostream>
#include "data_structures/lt_list.h"
#include "algorithm/lt_algo.h"

int main()
{
    lt::List<int> list;

    list.push_front(1);
    list.sort(lt::Less<int>());



    return 0;
}
