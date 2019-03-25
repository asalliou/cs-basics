#include "gtest/gtest.h"
#include "node.h"

TEST(node, count)
{
    struct node *head = NULL;
    head = insertHead(1, head);
    head = insertHead(2, head);
    head = insertHead(3, head);

    ASSERT_EQ(3, length(head));
}