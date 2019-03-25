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

    return 0;
}