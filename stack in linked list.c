#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push();
void pop();
void display();
struct node *head=NULL,*temp,*new;
int i;
int main(){
    int n;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    for( i=0;i<n;i++){
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data %d:",i+1);
        scanf("%d",&(new->data));
        if(head==NULL){ 
            head = new;   
            head->next=NULL;
        }
        else{
            new->next = temp;
            temp->next =NULL;
            head = new;
        }
        temp = new;     
    }
    
    display();
    push();
    pop();
    
}
void push(){
    new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&(new->data));
    temp = head;
    if(head == NULL){
        head = new;
        
        head->next = NULL;
        
    }
    else{

        new->next=head;
        head = new;       
    }
    display();
    
}
void pop(){
    if(head == NULL){
        printf("Stack is UnderFlow");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
    display();

}
void display(){
    temp = head;
    while(temp !=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}
