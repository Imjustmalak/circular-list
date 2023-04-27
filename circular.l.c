#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node** head, int data) {
    struct node* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head; 
    } else {
        struct node* p = *head;
        while (p->next != *head) {
            p = p->next;
        }
        p->next = new_node;
        new_node->next = *head; 
    }
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Empty list!\n");
        return;
    }
    
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n, data;
    struct node* head = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        printf("Enter data for node %d: ", j + 1);
        scanf("%d", &data);
        add_node(&head, data);
    }
    printf("Circular linked list contents: ");
    display(head);

    return 0;
}

 
