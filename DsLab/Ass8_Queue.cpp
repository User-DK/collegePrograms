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

class Queue{
    public:
    Node *front;
    Node *rear;
    Queue(): front(nullptr),rear(nullptr){}

    //enqueue

void enqueue(int data){
    Node *temp=new Node(data);
    if(rear==NULL){
        rear=front=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

//dequeue

void dequeue(){
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

//front
int front1(){
    if(front==NULL){
        return -1;
    }
    return front->data;
}

//size
int size(){
    int size=0;
    if(front==NULL){
        return size;
    }size++;
    Node *temp=front;
    while(temp->next!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}


//peek
int peek(int position){
    int x=size();
    if(position>x){
            cout<<"not in list";
            return -1;
    }
    Node *temp=front;
    int pos=1;
    while(temp->next!=NULL){
        if(pos==position){
            return temp->data;
        }
        pos++;
        temp=temp->next;
    }
    return pos;
}

//clear
void clear1(){
    Node *temp=front;
    Node *prev=NULL;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        delete prev;
    }
    front=rear=NULL;
}
};




int main() {
    Queue queue;

    int choice;
    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Peek\n";
        cout << "6. Clear Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                int data;
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;}
            case 2:{
                queue.dequeue();
                break;}
            case 3:{
                int x= queue.front1();
                if(x==-1){
                    cout<<"Queue Empty";
                }
                else{
                    cout << "Front element: " <<x<< endl;
                }
                break;}
            case 4:{
                cout << "Queue size: " << queue.size() << endl;
                break;}
            case 5:{
                int position;
                cout << "Enter the position to peek: ";
                cin >> position;
                int value = queue.peek(position);
                if (value != -1) {
                    cout << "Value at position " << position << ": " << value << endl;
                }
                break;}
            case 6:{
                queue.clear1();
                cout << "Queue cleared.\n";
                break;}
            case 7:{
                cout << "Exiting program.\n";
                break;}
            default:{
                cout << "Invalid choice. Please try again.\n";
                break;}
        }
    } while (choice != 7);

    return 0;
}
