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
    void insertAtIndex(int data, int index);
    void deleteFirst();
    void deleteLast();
    void deleteAtIndex(int index);
    static LinkedList mergeList(LinkedList& firstList, LinkedList& secondList);
    void displayList();
    int listSize();
};

#endif //PROG2400A2_LINKEDLIST_H
