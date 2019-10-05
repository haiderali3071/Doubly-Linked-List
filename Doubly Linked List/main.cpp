//
//  main.cpp
//  Doubly Linked List
//
//  Created by Haider Ali on 9/20/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
//#include "unistd.h"
using namespace std;

class Node {
    
public:
    Node *previous;
    int data;
    Node *next;
    
    Node(){
        previous = NULL;
        data = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    
    Node *first;
    Node *last;
    Node *loc;
    Node *ploc;
    
public:
    DoublyLinkedList(){
        
        first = NULL;
        last = NULL;
        loc = NULL;
        ploc = NULL;
    }
    
    bool isEmpty() {
        
        if (first == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void insertAtEnd(int value) {
    
    Node *temp = new Node();
    temp->data = value;
    
    if(isEmpty()) {
        
        first = temp;
        last = temp;
    }
    else {
        
        last->next = temp;
        temp->previous = last;
        last = temp;
    }
}
    
    void insertAtFront(int value) {
        
        Node *temp = new Node();
        temp->data = value;
        
        if(isEmpty()) {
            
            first = temp;
            last = temp;
        }
        else {
            temp->next = first;
            first->previous = temp;
            first = temp;
        }
    }
    
    void search(int value) {
        
        loc = first;
        ploc = NULL;
        
        while (loc != NULL && loc->data<value) {
            ploc = loc;
            loc = loc->next;
        }
        if(loc != NULL && loc->data != value) {
            loc = NULL;
        }
    }
    void insertSorted(int value) {
        
        search(value);
        if (loc != NULL) {
            cout<<"duplication is not allowed."<<endl;
            return;
        }
        if(ploc == NULL) {
            insertAtFront(value);
        }
        else {
            Node *temp = new Node();
            temp->data = value;
            temp->next = ploc->next;
            temp->previous = ploc;
            ploc->next = temp;
            if(temp->next != NULL){
                temp->next->previous = temp;
            }
            else {
                last = temp;
            }
        }
        
    }
    
    void printList() {
        
        if(!isEmpty()) {
            Node *temp= first;
            do{
                cout<<temp->data<<endl;
                temp = temp->next;
                
            }while(temp!=NULL);
        }
    }
    
    void reversePrint() {
        
        if(!isEmpty()) {
            Node *temp= last;
            do{
                cout<<temp->data<<endl;
                temp = temp->previous;
                
            }while(temp!=NULL);
        }
    }
    
    int deleteFront() {
        
        if(isEmpty()) {
            return NULL;
        }
        int data = first->data;
        Node *temp = first;
        first = first->next;
        delete temp;
        temp = NULL;
        if(first != NULL){
            first->previous = NULL;
        }
        return data;
    }
    
    int deleteLast() {
        
        if(isEmpty()) {
            return NULL;
        }
        search(last->data);
        
        int data = last->data;
        Node *temp = last;
        last = ploc;
        delete temp;
        temp = NULL;
        if(last != NULL){
            last->next = NULL;
        }
        else{
            first = NULL;
        }
        return data;
    }
    
    void deleteValue(int value) {
        
        if(isEmpty()) {
            return;
        }
        search(value);
        if(loc != NULL) {
            
            if(ploc == NULL) {
                deleteFront();
            }
            else {
                ploc->next = loc->next;
                if(loc->next != NULL) {
                     loc->next->previous = ploc;
                }
                else {
                     last = ploc;
                }
                delete loc;
                loc = NULL;
            }
        }
    }
    
    void destroyList() {
        
        if (isEmpty()) {
            return;
        }
        
        Node *temp;
        
        do {
            temp = first;
            first = first->next;
            delete temp;
        } while (first != NULL);
        temp = NULL;
    }
    
    //MARK: -  FOLLOWING ARE LAB AND HOME ACTIVITIES
    
    void reverseList() {
        
        if(isEmpty()) {
            return;
        }
        
        Node *temp = first;
        Node *nn;
        ploc = NULL;
        
        do{
            nn = temp;
            temp = temp->next;
            nn->next = ploc;
            nn->previous = temp;
            ploc = nn;
        }while(temp != NULL);
        
        nn = first;
        first = last;
        last = nn;
    }// end reverse list
    
    void swap(int value1, int value2) {
        
        Node *loc1;
        Node *ploc1;
        Node *temp;
        
        search(value1);
        loc1 = loc;
        ploc1 = ploc;
        search(value2);
        
        if(loc != NULL && loc1 != NULL) {
            
            if(ploc1 == NULL ) {
                //first value found at head node
                if (loc1 != ploc) {
                    temp = loc->next;
                    loc->next = loc1->next;
                    first = loc;
                    ploc->next = loc1;
                    loc1->next = temp;
                    
                    loc->previous = NULL;
                    loc->next->previous = loc;
                    loc1->previous = ploc;
                    if(temp!=NULL) {
                        temp->previous = loc1;
                    }
                    else {
                        last = loc1;
                    }
                   
                }
                else if (loc1 == ploc){
                    
                    first = loc;
                    temp = loc->next;
                    loc->next = loc1;
                    loc1->next = temp;
                    
                    loc->previous = NULL;
                    loc1->previous = loc;
                    if(temp!=NULL) {
                        temp->previous = loc1;
                    }
                    else {
                        last = loc1;
                    }
                }
                
            }
            else if(ploc == NULL){
                 //second value found at head node
                
                if (loc != ploc1) {

                    temp = loc1->next;
                    loc1->next = loc->next;
                    first = loc1;
                    ploc1->next = loc;
                    loc->next = temp;
                    
                    loc1->previous = NULL;
                    loc1->next->previous = loc1;
                    loc->previous = ploc1;
                    if(temp!=NULL) {
                        temp->previous = loc;
                    }
                    else {
                        last = loc;
                    }
                    
                } else if (loc == ploc1){
                    
                    first = loc1;
                    temp = loc1->next;
                    loc1->next = loc;
                    loc->next = temp;
                    
                    loc1->previous = NULL;
                    loc->previous = loc1;
                    if(temp!=NULL) {
                        temp->previous = loc;
                    }
                    else {
                        last = loc;
                    }
                }
               
            }
            else if(loc1 != ploc && loc != ploc1){
                temp = loc1->next;
                loc1->next = loc->next;
                if(loc->next != NULL) {
                    loc->next->previous = loc1;
                }
                else {
                    last = loc1;
                }
                ploc->next = loc1;
                loc1->previous = ploc;
                ploc1->next = loc;
                loc->previous = ploc1;
                loc->next = temp;
                if(temp != NULL) {
                    temp->previous = loc;
                }
                else {
                    last = loc;
                }
             }
            else{
                if(loc == ploc1) {
                    
                    ploc->next = loc1;
                    loc1->previous = ploc;
                    
                    temp = loc1->next;
                    loc1->next = loc;
                    loc->previous = loc1;
                    
                    loc->next = temp;
                    if(temp != NULL){
                        temp->previous = loc;
                    }
                    else {
                        last = loc;
                    }
                }
                else if (loc1 == ploc) {
                    
                    ploc1->next = loc;
                    loc->previous = ploc1;
                    
                    temp = loc->next;
                    loc->next = loc1;
                    loc1->previous = loc;
                    
                    loc1->next = temp;
                    if(temp != NULL) {
                        temp->previous = loc1;
                    }
                    else{
                        last = loc1;
                    }
                    
                }
            }
            
        }
        else {
            cout<<"Both values not found"<<endl;
        }
        
    }// end swap
    
    void makeGroupsOfOddEvenData() {
        
        Node *temp = first;
        Node *nFirst = NULL;
        first = NULL;
        Node *nn1 = NULL;
        Node *nn2 = NULL;
        
        while (temp != NULL) {
            
            if(temp->data % 2 == 1) {
                
                if(first != NULL) {
                    nn1->next = temp;
                    temp->previous = nn1;
                    nn1 = temp;
                }
                else {
                    first = temp;
                    nn1 = first;
                }
                ploc = temp;
            }
            else{
                if(nFirst != NULL) {
                    nn2->next = temp;
                    temp->previous = nn2;
                    nn2 = temp;
                }
                else {
                    nFirst = temp;
                    nn2 = nFirst;
                }
                loc = temp;
            }
            temp = temp->next;
        }
        
        if(first == NULL) {
            
            first = nFirst;
        }
        else {
            ploc->next = nFirst;
            nFirst->previous = ploc;
            if(nFirst != NULL){
                loc->next = NULL;
                last = loc;
            }
        }
       
    }//end grouping
    
};//end cirular link list class
