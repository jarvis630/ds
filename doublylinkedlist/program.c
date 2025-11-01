#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insertFront() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Error creating node\n");
        return;
    }
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    
    newnode->prev = newnode->next = NULL;
    
    if (head == NULL)
        head = newnode;
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertEnd() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Error creating node\n");
        return;
    }
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;
    
    if (head == NULL)
        head = newnode;
    else {
        struct node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertAtPosition() {
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Error creating node\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = newnode->next = NULL;
    if (pos == 1) {
        if (head == NULL)
            head = newnode;
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    } else {
        struct node *temp = head;
        for (i = 1;i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        if (temp->next)
            temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteFront() {
    if (head == NULL)
        printf("List empty\n");
    else {
        struct node *temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        free(temp);
    }
}

void deleteEnd() {
    if (head == NULL)
        printf("List empty\n");
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
}

void deleteAtPosition() {
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (head == NULL)
        printf("List empty\n");
    else if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        free(temp);
    } else {
        struct node *temp = head;
        for (i = 1;i < pos; i++)
            temp = temp->next;
        if (temp == NULL)
            printf("Invalid position\n");
        else {
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp->prev)
                temp->prev->next = temp->next;
            free(temp);
        }
    }
}

void search() {
    int key, pos = 1, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);
    struct node *temp = head;
    while (temp) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        printf("Element not found\n");
}

void display() {
    struct node *temp = head;
    if (head == NULL)
        printf("List empty\n");
    else {
        printf("List: ");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert at Front\n2.Insert at End\n3.Insert at Position\n4.Delete at Front\n5.Delete at End\n6.Delete at Position\n7.Search\n8.Display\n9.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
