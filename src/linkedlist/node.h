#pragma once

#include <string>
#include <iostream>

struct node {
  int data;
  struct node *next;
};

struct node* insert(int data, struct node *next) {
  struct node *new_node = (struct node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = next;
  return new_node;
}

void print(struct node *head) {
  struct node *current = head;
  while(current != NULL) {
    std::cout << "Data: " << current->data << std::endl;
    current = current->next;
  }
}

int length(struct node *head) {
  struct node *current = head;
  int count = 0;
  while(current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void swap(struct node **first, struct node **second) {
  struct node *buffer = *first;

  *first = *second;
  *second = buffer;
}