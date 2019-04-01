#include "gtest/gtest.h"
#include "hello.h"

TEST(hello, get_hello)
{
    std::string res = get_hello();
    ASSERT_EQ(res, "Hello World !!!");
}