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
    
    ASSERT_FALSE(map.get(0).has_value());
    map.put(1, 10);
    ASSERT_FALSE(map.get(21).has_value());
}

TEST(hashmap, remove)
{
    HashMap<int, int, MyKeyHash> map;
    
    map.put(1, 1);
    map.put(2, 2);
    
    map.remove(2);
    map.remove(3);
    
    ASSERT_TRUE(map.get(1).has_value());
    ASSERT_FALSE(map.get(2).has_value());
    
    map.put(21, 21);
    map.remove(1);
    
    ASSERT_FALSE(map.get(1).has_value());
    ASSERT_TRUE(map.get(21).has_value());
    
    map.put(41, 41);
    map.remove(41);
    
    ASSERT_FALSE(map.get(41).has_value());
    ASSERT_TRUE(map.get(21).has_value());

}
