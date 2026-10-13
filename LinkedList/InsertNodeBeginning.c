// Linked List: Inserting a node at beginning
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* Insert(Node *head, int x);     // Pass by value version
void Insert_Ref(Node **head, int x); // Pass by reference
void Print(Node *head);

int main() {
    Node *head = NULL; // empty list
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert_Ref(&head, x);
        Print(head);
    }
}

Node* Insert(Node *head, int x) {
    Node *temp = malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = NULL;
    if (head != NULL) temp -> next = head;
    head = temp;
    return head;
}

void Insert_Ref(Node **head, int x) {
    Node *temp = malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = NULL;
    if(*head != NULL) temp -> next = *head;
    *head = temp;
} 


/*
Explanation: Remember that the value of head is an address itself. That address
gets copied into this function. So we have 2 heads right here.

The original that points to some address.
This one that started pointing at that address, but won't change the original one,
because we are not changing the value of the head address variable. To do that, 
we should've used **head instead as a parameter and pass the reference of head when
calling with the &. Check Insert_Ref for reference.

*/
void Print(Node *head) {
    // Node *temp = head;  This was uncommented when head was a global variable
    printf("List is: ");
    while (head != NULL) {
        printf(" %d", head -> data);
        head = head -> next;
    }
    printf("\n");
}
