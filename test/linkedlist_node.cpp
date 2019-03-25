#include "gtest/gtest.h"
#include "node.h"

TEST(node, count)
{
    struct node *head = nullptr;
    head = insertHead(1, head);
    head = insertHead(2, head);
    head = insertHead(3, head);

    ASSERT_EQ(3, length(head));
}

TEST(node, getNth)
{
    struct node *head = nullptr;
    head = insertHead(1, head);
    head = insertHead(2, head);
    head = insertHead(3, head);

    int error = 0;
    ASSERT_EQ(2, getNth(head, 1, &error));

    ASSERT_EQ(-1, getNth(head, 3, &error));
    ASSERT_EQ(1, error);
}