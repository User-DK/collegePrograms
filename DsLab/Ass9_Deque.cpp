#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

class Queue
{
public:
    Queue()
    {
        Node *front = nullptr;
        Node *rear = nullptr;
    }
};
// Insertion
void pushFront(int data, Node *front,Node *rear)
{
    if(front==NULL){
        rear=front=new Node(data);
    }
    else{
        front=new Node(data,front);
    }
}

void pushBack(int data, Node *front,Node *rear)
{
    Node *temp=new Node(data);
    if(front==NULL){
        rear=front=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

// Deletion
void popFront(Node *front,Node *rear)
{
    if(front==NULL){
        cout<<"QUEUE Empty";
        return;
    }
    Node *temp=front;
    front=front->next;
    delete temp;
    if(front==NULL){
        rear=front;
    }
}


void popBack(Node *front,Node *rear)
{
    if(rear=NULL){
        cout<<"QUEUE Empty";
        return;
    }
    Node *temp=front;
    while(temp->next!=rear){
        temp=temp->next;
    }
    rear=temp;
    rear->next=NULL;
    delete temp->next;
    if(rear==NULL){
        
    }
}

// front rear
int front()
{
}
int back()
{
}

int size()
{
}

bool isEmpty()
{
}

// Peek (Access):

int peekFront(int position)
{
}
int peekBack(int position)
{
}

void clear()
{
}

// Traverse and Display:
void traverse()
{
}

int main()
{
}