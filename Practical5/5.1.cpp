#include <iostream>
using namespace std;

struct Node{
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insert_at_front(string song){
    Node* newNode = new Node;

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if(head!=NULL){
        head->prev = newNode;
    }
    head = newNode;
}

void insert_at_end(string song){
    Node* newNode = new Node;

    newNode->song = song;
    newNode->next = NULL;

    if(head==NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next!=NULL)
    temp=temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insert_after(string givenSong, string newSong){
    Node* temp = head;

    while(temp!=NULL && temp->song!=givenSong){
        temp=temp->next;
    }

    if(temp==NULL){
        cout<<"Given song not found"<<endl;
        return;
    }

    Node* newNode = new Node;

    newNode->song = newSong;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next!=NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void remove_first(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head!=NULL){
        head->prev = NULL;
    }

    delete temp;
}

int countSongs(){
    int count = 0;
    Node* temp = head;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
}

void display(){
    Node* temp = head;

    cout<<"Playlist:";

    while(temp!=NULL){
        cout<<" "<<temp->song;
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    insert_at_end("Song A");
    insert_at_end("Song B");
    insert_at_front("Song C");
    insert_after("Song A", "Song D");

    display();

    cout<<"Total songs: "<<countSongs()<<endl;

    remove_first();
    display();

    return 0;
}