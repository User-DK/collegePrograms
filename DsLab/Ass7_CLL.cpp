#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr){}
    Node(int data) : data(data), next(nullptr){}
    Node(int data, Node *next) : data(data), next(next){}
};


//insertion:
void insertAtBeginning(int data, Node *head){
    Node* newNode= new Node(data);
    if(head==NULL){
        head=newNode;
        head->next=head;
    }
    else{
    newNode->next=head;
    Node *temp=end(head);
    head=newNode;
    temp->next=head;
    }
}

void insertAtEnd(int data, Node *head){
    Node* newNode= new Node(data);
    if(head==NULL){
        head=newNode;
        head->next=head;
    }
    else{
        Node *temp=end(head);
        temp->next=newNode;
        newNode->next=head;
    }
}

void insertAfter(int data, int key, Node *head){
    Node* temp=head;
    while(temp->next!=head){
        if(temp->data==key){
            break;
        }
        temp=temp->next;
    }
    if(temp->data==key){
        temp->next=new Node(data, temp->next);
    }
    else{
        cout<<"Key Not Found";
    }
}

void insertBefore(int data, int key, Node *head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=head){
        prev=temp;
        if(temp->data==key){
            break;
        }
        temp=temp->next;
    }
    if(temp->data==key && prev==NULL){
        prev=new Node(data, temp);
    }
    else if(temp->data==key && prev!=NULL){
        prev->next=new Node(data, prev->next);
    }
    else{
        cout<<"Key Not Found";
    }
}

// void insertAtPosition(int data, position)



//deletion

void deleteCL(int data){
    
}

// void deleteAtPosition(position)

void deleteAtBeginning(){

}

void deleteAtEnd(){

}

//traversal

Node *getHead(){

}

void isEmpty(){

}

int size(){

}

Node *search(int data){

}

//Modification

void update(int data, int newData){

}

//Access

int getAtPosition(int position){

}

//traversal and display

void traverse(){
    
}


Node *end(Node* head){
    Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    return temp;
}

int main(){

}