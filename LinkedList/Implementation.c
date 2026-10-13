#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head;
    head = NULL;

    struct Node *temp = malloc(sizeof(struct Node));
    
    temp -> data = 2;
    temp -> next = NULL;

    head = temp;

    // Creating new node in the list
    temp = malloc(sizeof(struct Node));
    temp -> data = 4;
    temp -> next = NULL;

    struct Node *temp1 = head;

    // Traverse the list until end to connect new node
    while (temp1 -> next != NULL) {
        temp1 = temp1 -> next;
    }

    temp1 -> next = temp;

    // Traverse the list to print it's elements
    temp1 = head;
    // Traverse the list until end to connect new node
    while (temp1 -> next != NULL) {
        printf("%d -> ", temp1 -> data);
        temp1 = temp1 -> next;
    }
    printf("%d\n", temp1 -> data);
}
