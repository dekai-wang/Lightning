//
//  main.cpp
//  Lightning
//
//  Created by admin on 2017/11/10.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include "lt_priority_queue.h"
#include "lt_sort.h"
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...

    std::vector<int> vec = { 9, 3, 6, 7, 1, 8, 4, 5, 2};
  
    lt::Sort::HeapSort<int>(vec);
    
    return 0;
}
