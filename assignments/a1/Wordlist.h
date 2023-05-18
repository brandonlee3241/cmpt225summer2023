// Wordlist.h

#pragma once

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <put your full name here!>
// St.# : <put your full SFU student number here>
// Email: <put your SFU email address here>
//
//
// Statement of Originality
// ------------------------

// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

//
// Do not use any other #includes
//
#include "Wordlist_base.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Wordlist : public Wordlist_base
{
    struct Node
    {
        string word;
        int count;
        Node *next;
        Node(const string& w, int c, Node* n) : word(w), count(c), next(n) {}

    };
    
    private:
        Node* head; // head pointer 
        string word; 
    public:
        Wordlist(){ // empty list constructor
            head = nullptr;
        }

        Wordlist(string &filename){ //populate list with words from file
            ifstream file(filename);
            while (file >>word){
                add_word(word);
            }
        }

        ~Wordlist(){
            Node* tmp = head;
            while(head){
                tmp = head;
                head = head->next;
                delete(tmp);
            }
        }


        //methods:

        
        int get_count(const string &w)const override{
            Node* p = head; //temp pointer to traverse
            if(p == nullptr){
                return 0;
            }
            while(p->word != w){ // this will walk the pointer until we reach the correct word
                p = p->next;
                if(!p){
                    return 0;
                }
            }
            return p->count;
        }
        
        void add_word(const string &w)override{
            Node* p = head;
            Node* tmp =nullptr;
            if(p == nullptr){ // checks if list is empty, if so make a new node and set it as the head;
                head = new Node(w,1,nullptr);
                return;
            }
            while(p!=nullptr && p->word.compare(w)<0){
                tmp = p;
                p = p->next;
            }
            if(p && p->word == w){
                p->count +=1;
                return;
            }
            Node* newNode = new Node(w,1,p);
            if(tmp){
                tmp->next = newNode;
            }
            else{
                head = newNode;
            }

        }
        string most_frequent()const override{
            Node* p = head; // p will be used to traverse the list
            Node* tmp = nullptr; //tmp will be used to keep track of the node that contains the most frequent word
            int max=0; // will be used for comparisons
            while(p){
                if(p->count > max){
                    tmp = p;
                    max = tmp->count;
                }
                p = p->next;
            }
            if(tmp){
                return tmp->word;
            }
            else{
                return ""; //returns null if list is empty;
            }
            
        }
        int num_different_words()const override{
            int count=0;
            Node* p = head;
            while(p){
                count+=1;
                p = p->next;
            }
            return count; // accounts for if head == null
        }
        int num_singletons()const override{
            int count=0;
            Node* p = head;
            while(p){
                if(p->count == 1){
                    count+=1;
                }
                p = p->next;
            }
            return count;
        }
        bool is_sorted()const override{
            Node* p = head;
            while(p){
                if(p->next && p->next->word < p->word){
                    return false;
                }
                p = p->next;
            }
            return true;
        }
        int total_words()const override{
            int count = 0;
            Node* p = head;
            while(p){
                count+=p->count;
                p = p->next;
            }
            return count;
        }
        void print_words()const override{
            Node* p = head;
            int count =0;
            while(p){
                count+=1;
                cout << count << ". {"<<p->word<<", "<<p->count << "}"<<endl;
                p = p->next;
            }
        }
    //
    // ... your code goes here ...


    //
    // ... you can write helper methods if you need them ...
    //

    //
    // ... write a default constructor that creates an empty Wordlist ...
    //

}; // class Wordlist

//
// ... you can write helper functions here (or before Wordlist) if you need them
// ...
//

//
// ... write functions to test every method of Wordlist ...
//
