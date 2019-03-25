#include <iostream>
#include "node.h"

int main() {
    struct node *head = NULL;

    head = insert(1, head);
    head = insert(2, head);
    head = insert(3, head);
    head = insert(9, head);
    
    print(head);

    std::cout << "Count: " << length(head) << std::endl;

    struct node *first = (struct node *)malloc(sizeof(node));
    first->data = 10;

    struct node *second = (struct node *)malloc(sizeof(node));
    second->data = 11;

    std::cout << "First: " << first->data << " Second: " << second->data << std::endl;

    swap(&first, &second);
    std::cout << "First: " << first->data << " Second: " << second->data << std::endl;
    

    return 0;
}