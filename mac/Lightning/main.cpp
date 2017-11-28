//
//  main.cpp
//  Lightning
//
//  Created by admin on 2017/11/10.
//  Copyright © 2017年 admin. All rights reserved.
//

#include <iostream>
#include "lt_hash_table.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    lt::HashTable<const char*, int> h;
    
    h.insert("123", 123);
    return 0;
}
