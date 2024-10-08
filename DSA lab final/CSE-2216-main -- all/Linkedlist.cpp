//
// Created by Iftekharul Abedeen on 20/6/23.
//

#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* LL_insert_to_beginning(Node* head,int newData){ //needs assignment
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> next = head;
    return newNode;
}

void LL_insert_to_beginning(Node** head,int newData){ //One without assignment needed
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> next = *head;
    *head = newNode;
}

void LL_insert_before(Node** head, int newdata, int target){
    Node* temp = *head;
    Node* newNode = new Node();
    newNode -> data = newdata;
    if(temp -> data == target){
        LL_insert_to_beginning(head, newdata);
        return;
    }
    while(temp -> next -> data != target && temp -> next != NULL){
        temp = temp ->next;
        if(temp -> next == NULL){
            break;
        }
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return;
}

void LL_insert_after(Node* head, int newData, int target){
    Node* temp = head;
    while(temp -> next != NULL && temp -> data != target){
        temp = temp -> next;
    }
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void LL_insert_at_end(Node* head, int newData){
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node();
    newNode -> data = newData;
    temp -> next = newNode;
}

void LL_delete_node(Node** head, int hasValue){
    Node* temp = *head;
    if(temp -> data == hasValue){
        *head = temp -> next;
        free(temp);
        return;
    }
    Node* prevNode;
    while(temp != NULL && temp -> data != hasValue){
        prevNode = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode -> next = temp -> next;
    free(temp);
}

int main(){
    Node* head;

    head = new Node();
    head -> data = 1;


    head = LL_insert_to_beginning(head,3);
    LL_insert_to_beginning(&head, 4);

    LL_insert_after(head,2,3);

    LL_insert_at_end(head, 0);

    LL_delete_node(&head,10);
    LL_insert_before(&head, 400,4);
    LL_insert_before(&head, 300,3);
    LL_insert_before(&head, 700,7);
    Node* Cursor;
    Cursor = head;
    while(Cursor){
        cout << Cursor -> data << endl;
        Cursor = Cursor -> next;
    }
    return 0;
}
