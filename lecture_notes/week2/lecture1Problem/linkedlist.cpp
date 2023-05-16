#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

typedef struct node{
    node* next;
    string value;
}node;

int main(){
   // new node{nullptr,"cat"};
    node* head = new node{nullptr,"bird"}; // head is set to a new node, cat
    head = new node{head,"dog"};
    head = new node{head, "cat"};    
    cout<< head->value;
    cout<< head->next->value;
    cout<< head->next->next->value;

    node* del = head;
    while(head){
        del = head;
        head = head->next;
        delete(del);
    }
    
}