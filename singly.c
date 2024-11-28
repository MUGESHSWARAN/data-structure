#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Element %d inserted at the front successfully.\n", data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    new=(struct node*)malloc(sizeof(structnode);
if(head==null)
{
printf("memory is not allocated");
}
else
{
int data;
printf("enter the data"};
scanf("%d",&data);
new->data=data;
temp=head
  while(temp->next!=null);
{
temp=temp->next;
}
temp->next=newnode;
new->next=null;
}

// Function to insert a node in the middle after a given value
void insertInMiddle(struct Node** head, int after, int data) {
struct node*create node(data);
new=(struct node*)malloc(sizeof(stuctnode);
if(head=null);
{
printf("memory allocated");
}
else
}
int data,pos;
printf("element ");
  scanf("%d",data);
printf("position");
scanf("%d",pos);
temp=head;
for(int i=1;i<pos;i++);
{
temp=temp->next;
}
newnode->temp=next
  temp->next=>newnode
  }

// Function to delete a node from the front
void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
    }
else
{
while(temp->next!=null);
{
printf("%d",temp->data);
temp=temp->next;
}
printf("%d",temp->data);
temp=temp->next;
}


// Function to delete a node from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    printf("Element %d deleted from the end successfully.\n", temp->data);
    free(temp);
}

// Function to delete a node in the middle by value
void deleteInMiddle(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found. Cannot delete.\n", key);
        return;
    }
    if (prev == NULL) { // Key is in the head
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    printf("Element %d deleted successfully.\n", key);
    free(temp);
}

// Function to search for a node with a specific value
void searchNode(struct Node* head, int key) {
    int position = 0;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d.\n", key, position + 1);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, after;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in middle after a value\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete a specific value (middle)\n");
        printf("7. Search element\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &after);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertInMiddle(&head, after, value);
                break;
            case 4:
                deleteAtFront(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteInMiddle(&head, value);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(head, value);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
