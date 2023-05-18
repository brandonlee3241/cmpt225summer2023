// Wordlist.h

#pragma once

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Brandon Lee>
// St.# : <redacted>
// Email: <redacted>
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

        ~Wordlist(){ // destructor to delete all nodes in list
            Node* tmp = head;
            while(head){
                tmp = head;
                head = head->next;
                delete(tmp);
            }
        }


        //methods:
        // The basis for most of these methods is to use one temporary node pointer to traverse the list 
        // until we reach the desired location or node. Many of the methods will for the most part follow 
        // the same structure, as most of the methods are a test of our ability to access data in a singly linked
        // list, so I will only comment the first one in detail, and then will add comments 
        // where there are differences.
        // 

        
        int get_count(const string &w)const override{
            Node* p = head; //temp pointer to traverse the list
            if(p == nullptr){ // checks if list is empty and returns 0 if so
                return 0;
            }
            while(p->word != w){ // this will walk the pointer until we reach the desired word or the end of the list
                p = p->next;
                if(!p){ // if we reach the end of the list and the word is not found, return 0
                    return 0;
                }
            }
            return p->count;
        }
        
        void add_word(const string &w)override{
            Node* p = head; 
            Node* tmp =nullptr; // tmp will be used to keep track of the node before the node we want to insert
            if(p == nullptr){ // checks if list is empty, if so make a new node and set it as the head
                head = new Node(w,1,nullptr);
                return;
            }
            while(p!=nullptr && p->word.compare(w)<0){ // this will walk the pointer until we reach the correct spot to insert the word
                tmp = p;
                p = p->next;
            }
            if(p && p->word == w){ // if the word is already in the list, increment the count and return
                p->count +=1;
                return;
            }
            Node* newNode = new Node(w,1,p); 
            if(tmp){ // if tmp is not null, we are not inserting at the head
                tmp->next = newNode;
            }
            else{// if tmp is null, we are inserting at the head
                head = newNode;
            }

        }

        string most_frequent()const override{
            Node* p = head; 
            Node* tmp = nullptr; //tmp will be used to keep track of the node with the highest count
            int max=0; // max will be used to keep track of the highest count
            while(p){
                if(p->count > max){
                    tmp = p;
                    max = tmp->count;
                }
                p = p->next;
            }
            if(tmp){ // if tmp is not null, return the word with the highest count
                return tmp->word;
            }
            else{
                return ""; //returns null if list is empty;
            }
            
        }

        int num_different_words()const override{
            int count=0; // initialize to 0 in case list is empty
            Node* p = head;
            while(p){ // walks the pointer to the end of the list and increments count
                count+=1;
                p = p->next;
            }
            return count;
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
                if(p->next && p->next->word < p->word){ // checks if the next word is less than the current word
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
    

}; 