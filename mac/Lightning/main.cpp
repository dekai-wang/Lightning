//
//  main.cpp
//  Lightning
//
//  Created by admin on 2017/11/10.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include "lt_priority_queue.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    lt::PriorityQueue<int> qu;
    
    for (int i = 1; i < 10; i++)
    {
        qu.insert(i);
    }
    
    for (int i = 1; i < 10; i++)
    {
        std::cout << qu.erase_min() << std::endl;
    }
    
    return 0;
}
