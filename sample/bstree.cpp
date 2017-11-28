#include <iostream>
#include "data_structures/lt_bstree.h"

int main()
{
    lt::BSTree<int, int> bstree;

    for (int i = 1; i < 20; i++)
    {
        bstree.insert(i, i);
    }


    return 0;
}
