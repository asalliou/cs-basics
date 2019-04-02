#include "gtest/gtest.h"
#include "hashmap.h"

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};

TEST(hashmap, getput)
{
    HashMap<int, int, MyKeyHash> map;
    map.put(1, 1);
    map.put(2, 2);
    
    ASSERT_EQ(1, map.get(1));
    ASSERT_EQ(2, map.get(2));
    
    map.put(1, 10);
    map.put(21, 11);
    
    ASSERT_EQ(10, map.get(1));
    ASSERT_EQ(11, map.get(21));
}

TEST(hashmap, edge)
{
    HashMap<int, int, MyKeyHash> map;
    
    //ASSERT_EQ(0, map.get(0));
    //map.put(1, 10);
    //ASSERT_EQ(nullptr, map.get(21));
}
