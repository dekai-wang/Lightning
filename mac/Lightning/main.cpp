//
//  main.cpp
//  Lightning
//
//  Created by admin on 2017/11/10.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include "lt_bstree.h"
#include "lt_avltree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lt::BSTree<int> b;
    for (int i = 0; i < 5; i++)
        b.insert(i);
    
    b.remove(3);
    
    lt::AVLTree<int> avl;
    for (int i = 1; i < 7; i++)
        avl.insert(i);
    
    std::cout << "Hello, World!\n";
    return 0;
}
