#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

int count = 0;
struct node *head = NULL, *temp = NULL, *new_node = NULL, *tail = NULL;

void createNode();
void insert();
void display();
void create();
void deleteNode();
void search();

void createNode() {
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
}

int main() {
    int choice;
    printf("To perform any operations Enter..\n");
    printf("1 -> Create\n");
    printf("2 -> Insert\n");
    printf("3 -> Delete\n");
    printf("4 -> Search\n");
    printf("5 -> Display\n");
    printf("0 -> Exit\n");

    printf("\t__\n");
    
    do {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}

void create() {
    int data, choice;
    do {
        printf("Do you want to add node (1 or 0): ");
        scanf("%d", &choice);
        if (choice == 1) {
            createNode();
            printf("Enter the data: ");
            scanf("%d", &(new_node->data));
            if (head == NULL) {
                head = new_node;
                temp = head;
            } else {
                temp->next = new_node;
                new_node->prev = temp;
                temp = temp->next;
            }
            tail = temp;
            count++;
        }
    } while (choice != 0);
    printf("\nTotal Nodes: %d\n", count);
}

void display() {
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert() {
    int pos;
    createNode();
    printf("Enter the data: ");
    scanf("%d", &(new_node->data));
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    temp = head;
    if (pos == 1) {
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        if (tail == NULL) {
            tail = new_node;
        }
    } else {
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        if (new_node->next == NULL) {
            tail = new_node;
        }
    }
    count++;
}

void deleteNode() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        free(temp);
    } else {
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        temp->prev->next = temp->next;
        free(temp);
    }
    count--;
}

void search() {
    int element, found = 0;
    printf("Enter the Element to search: ");
    scanf("%d", &element);

    temp = head;
    while (temp != NULL) {
        if (temp->data == element) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        printf("%d is found in the list.\n", element);
    } else {
        printf("%d is not found in the list.\n", element);
    }
}
