#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithm/lt_sort.h"

int main()
{
    std::vector<int> vec = {3,2,1};

    lt::Sort::InsertSort<int>(vec);

    for (auto it : vec)
        std::cout << it << std::endl;


    return 0;
}
