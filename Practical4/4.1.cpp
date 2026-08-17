//Practical 4.1

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Linkedlist{
    public:
    Node* head;
    Node* tail;

    Linkedlist(){
        head = NULL;
        tail = NULL;
    }

//Insert at front
void insert_at_front(int x){
    Node* newNode = new Node(x);

    if(head == NULL){
        head = tail = newNode;
        return;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

//Insert at end
void insert_at_end(int x){
    Node* newNode = new Node(x);

    if(head == NULL){
        head = tail = newNode;
        return;
    }else{
        tail->next = newNode;
        tail= newNode;
    }  
}

//Insert in middle
void insert_in_middle(int pos, int x){
    if(pos<0){
        cout<<"Invalid";
        return;
    }
    if(pos == 0){
        insert_at_front(x);
        return;
    }

    Node* temp = head;

    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    Node* newNode = new Node(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void print_ll(){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};

int main(){
    Linkedlist q;

    q.insert_at_front(20);
    q.print_ll();

    q.insert_at_end(40);
    q.print_ll();

    q.insert_at_end(50);
    q.print_ll();

    q.insert_at_front(10);
    q.print_ll();

    q.insert_in_middle(2,30);
    q.print_ll();

    return 0;
}