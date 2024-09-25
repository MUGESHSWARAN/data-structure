#include<stdio.h>
#define size 100
int a[size];
int top=-1;
int push();
int pop();
int display();
int push(int data){
    if(top==size-1){
        printf("Stack OverFlow");
    }
    else{
        top++;
        a[top]=data;
        
    }
}
int pop(){
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        top--;
    }
}
int display(){
    for(int i=top;i>=0;i--){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int main(){
    push(300);
    push(205);
    push(400);
    push(450);
    display();
    pop();
    display();
}
