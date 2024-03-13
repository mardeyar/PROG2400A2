#include <iostream>
#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

// Insertion at list beginning
void LinkedList::insertStart(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode-> next = head;
    head = newNode;
}

// Insertion at list end
void LinkedList::insertEnd(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Insertion at index
void LinkedList::insertAtIndex(int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Delete from first node
void LinkedList::deleteFirst() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from last node
void LinkedList::deleteLast() {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

// Delete from a given index
void LinkedList::deleteAtIndex(int index) {
    if (head == nullptr) {
        return;
    }

    if (index == 0) {
        deleteFirst();
        return;
    }

    Node* current = head;

    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Split list into halves
void LinkedList::frontBackSplit(LinkedList &frontList, LinkedList &backList) {
    if (head == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    frontList.head = head;
    backList.head = slow->next;
    slow->next = nullptr;
}

// Merge two lists
LinkedList LinkedList::mergeList(LinkedList &firstList, LinkedList &secondList) {
    LinkedList mergedList;
    Node* currentList1 = firstList.head;
    Node* currentList2 = secondList.head;

    while (currentList1 != nullptr && currentList2 != nullptr) {
        if (currentList1->data <= currentList2->data) {
            mergedList.insertEnd(currentList1->data);
            currentList1 = currentList1->next;
        } else {
            mergedList.insertEnd(currentList2->data);
            currentList2 = currentList2->next;
        }
    }

    while (currentList1 != nullptr) {
        mergedList.insertEnd(currentList1->data);
        currentList1 = currentList1->next;
    }

    while (currentList2 != nullptr) {
        mergedList.insertEnd(currentList2->data);
        currentList2 = currentList2->next;
    }

    return mergedList;
}

void LinkedList::displayList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}