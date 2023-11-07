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

class Stack{
    public:
    Node * top;
    Stack():top(nullptr){}
};

//insertion
void push(int data, Node * top){
    if(top==NULL){
        top=new Node(data);
        return;
    }
    top=new Node(data, top);
    return;
}

//deletion
int pop(Node *top){
    Node *temp=top;
    int x=top->data;
    top=top->next;
    delete temp;
    return x;
}

//top
int top(Node *top){
    return top->data;
}

//size
int size(Node *top){
    Node *temp=top;
    int size=1;
    while(temp->next!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}

//empty
bool isEmpty(Node *top){
    if (top==NULL){
        return true;
    }
    return false;
}

//peek
int peek(int position , Node *top){
    int x=size(top);
    if(position>x){
        cout<<"position more than stack size";
        return -1;
    }
    int size=1;
    Node *temp=top;
    while(temp->next!=NULL){
        if(size==position){
            return temp->data;
        }
        temp=temp->next;
    }
}

//clear
void clear(Node *top){
    Node *temp=top;
    Node *prev=NULL;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        delete prev;
    }
}

void traversal(){
    
}

int main(){
    
}


