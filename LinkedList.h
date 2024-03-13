#ifndef PROG2400A2_LINKEDLIST_H
#define PROG2400A2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insertStart(int data);
    void insertEnd(int data);
    void insertAtIndex(int data);
    void deleteFirst();
    void deleteLast();
    void deleteAtIndex(int index);
    void frontBackSplit(LinkedList& frontList, LinkedList& backList);
    static LinkedList mergeList(LinkedList& firstList, LinkedList& secondList);
    void displayList();
};

#endif //PROG2400A2_LINKEDLIST_H
