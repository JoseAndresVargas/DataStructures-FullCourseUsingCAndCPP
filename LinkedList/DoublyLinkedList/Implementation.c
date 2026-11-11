/* Doubly Linked List implementation */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head; // global variable - pointer to head node.

void InsertAtHead(int x);
Node* GetNewNode(int x);

int main() 
{
    head = NULL;
    InsertAtHead(5);
    InsertAtHead(2);
}

void InsertAtHead(int x) 
{
    Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

Node* GetNewNode(int x) 
{
    Node* newNode = malloc(sizeof(Node));
    
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}
