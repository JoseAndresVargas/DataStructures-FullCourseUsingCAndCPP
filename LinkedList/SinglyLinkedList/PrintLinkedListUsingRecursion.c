#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *Insert(Node *head, int data) {
    Node *temp = malloc(sizeof(Node));
    temp -> data = data;
    temp -> next = NULL;
    if (head == NULL) head = temp;
    else {
        Node *temp1 = head;
        while (temp1 -> next != NULL) temp1 = temp1 -> next;
        temp1 -> next = temp;
    }
    return head;
}

void Print(struct Node *head) {
    if (head == NULL) {  // Exit condition
        return; 
    }
    printf("%d ", head->data);  // First print the value
    Print(head->next); // Recursive call
}

void PrintReverse(struct Node *head) {
    if (head == NULL) {
        return;
    }
    PrintReverse(head -> next);
    printf("%d ", head -> data);
}

int main() {
    Node *head = NULL; // local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    printf("\n");
    PrintReverse(head);
    printf("\n");
}
