#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithm/lt_sort.h"

int main()
{
    std::vector<int> vec = {7,4,9,1,3,8,6,2,5};

    //lt::Sort::InsertSort<int>(vec);
    lt::Sort::MergeSort<int>(vec);

    for (auto it : vec)
        std::cout << it << std::endl;


    return 0;
}
