#include <iostream>
#include "data_structures/lt_hash_table.h"

int main()
{

    std::cout << "hash" << std::endl;
    lt::HashTable<const char*, int> h;
    
    h.insert("123", 123);

    int val = h.find("123");

    std::cout << val << std::endl;
 
    return 0;
}
