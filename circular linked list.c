#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node* next;
};

struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}

void insertEnd(struct Node** head, int data) {
 struct Node* newNode = createNode(data);
 if (*head == NULL) {
 *head = newNode;
 newNode->next = *head;
 } else {
 struct Node* temp = *head;
 while (temp->next != *head) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
}

void deleteNode(struct Node** head, int data) {
 struct Node *temp = *head, *prev = NULL;
 if (temp != NULL && temp->data == data) {
 *head = temp->next;
 free(temp);
 return;
 }
 while (temp != NULL && temp->data != data) {
 prev = temp;
 temp = temp->next;
 }
 if (temp == NULL) return;
 prev->next = temp->next;
 free(temp);
}

void displayList(struct Node* head) {
 struct Node* temp = head;
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
}
int main() {
 struct Node* head = NULL;insertEnd(&head, 1);
 insertEnd(&head, 2);
 insertEnd(&head, 3);
 
 printf("Singly Linked List: ");
 displayList(head);
 deleteNode(&head, 2);
 printf("After deleting 2: ");
 displayList(head);
 
}
