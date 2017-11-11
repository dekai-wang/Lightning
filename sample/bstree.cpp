#include <iostream>
#include "data_structures/lt_bstree.h"

int main()
{
    lt::BSTree<int> bstree;

    for (int i = 1; i < 20; i++)
    {
        bstree.insert(i);
    }

    bstree.remove(5);
    bstree.remove(9);

    return 0;
}
