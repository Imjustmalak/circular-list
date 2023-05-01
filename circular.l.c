#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node() {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node **head) {
    struct node *new_node = create_node();
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *ptr = *head;
        while (ptr->next != *head) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    new_node->next = *head;
}



            
            




void display(struct node *head) {
    if (head == NULL) {
        printf("the list is empty");
        return;
    }
    struct node *temp = head;
    do {
        printf("%d, ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    struct node *head = NULL;
    printf("Enter the number of elements you want to add: ");
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        add_node(&head);
    }
    printf("your linked list contents: ");
    display(head);
   
}
