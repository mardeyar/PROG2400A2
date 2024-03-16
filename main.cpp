#include <iostream>
#include "LinkedList.h"

int main() {
    // Start program: instantiate list , set seed for randomNum and populate 8 ints into list to start
    LinkedList list;
    srand(time(nullptr));
    for (int i = 0; i < 5; i++) {
        int randomNum = rand() % 100;
        list.insertEnd(randomNum);
    }

    std::cout << "*** METHOD TESTING ***\n" << std::endl;

    // Method testing: insert at start, end, and a given index
    int randomNum = rand() % 100;
    list.insertStart(randomNum);
    std::cout << "List after running insertStart: ";
    list.displayList();

    randomNum = rand() % 100;
    list.insertEnd(randomNum);
    std::cout << "\nList after running insertEnd: ";
    list.displayList();

    int index = rand() % (list.listSize() + 1);
    randomNum = rand() % 100;
    list.insertAtIndex(randomNum, index);
    std::cout << "\nList after running insertAtIndex: ";
    list.displayList();

    list.deleteFirst();
    std::cout << "\nList after running deleteFirst: ";
    list.displayList();

    list.deleteLast();
    std::cout << "\nList after running deleteLast: ";
    list.displayList();

    index = rand() % (list.listSize() + 1);
    list.deleteAtIndex(index);
    std::cout << "\nList after running deleteAtIndex: ";
    list.displayList();

    //Create two new one way link lists
    LinkedList listA, listB;
    for (int i = 0; i < 5; i++) {
        randomNum = rand() % 100;
        listA.insertEnd(randomNum);
        randomNum = rand() % 100;
        listB.insertEnd(randomNum);
    }

    std::cout << "\nList A: ";
    listA.displayList();
    std::cout << "\nList B: ";
    listB.displayList();

    LinkedList mergedList = LinkedList::mergeList(listA, listB);

    std::cout << "\nList after running mergeList: ";
    mergedList.displayList();

    return 0;
}
