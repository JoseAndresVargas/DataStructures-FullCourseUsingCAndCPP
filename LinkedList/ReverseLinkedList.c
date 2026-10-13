#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *Insert(Node *head, int x);     // Pass by value version
Node *Reverse(Node *head);
void Print(Node *head);

int main() {
    Node *head = NULL; // local variable
    head = Insert(head, 2); 
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head = Reverse(head);
    Print(head);
}


Node* Insert(Node *head, int x) {
    Node *temp = malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = NULL;
    if (head != NULL) temp -> next = head;
    head = temp;
    return head;
}

Node* Reverse(Node *head) {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void Print(Node *head) {
    // Node *temp = head;  This was uncommented when head was a global variable
    printf("List is: ");
    while (head != NULL) {
        printf(" %d", head -> data);
        head = head -> next;
    }
    printf("\n");
}
