#include <iostream>

#include "hashmap.h"

using namespace std;

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};

int main() {
    HashMap<int, int, MyKeyHash> map;
    map.put(1, 3);
    map.put(21, 5);
    
    std::cout << map.get(1) << std::endl;
    std::cout << map.get(21) << std::endl;

    return 0;
}
