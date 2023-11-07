# include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}


void insertAtBeggining(struct Node** head,int data){
    struct Node* newnode=createNode(data);
    newnode->next=*head;
    *head=newnode;
}

int main(){

}