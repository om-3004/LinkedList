#include <iostream>
#include "./include/linkedlist.h"

int main()
{
    LinkedList l1{20, 30};
    l1.displayList();
    
    l1.insertNodeStart(10);
    l1.displayList();
    
    l1.insertNodeEnd(50);
    l1.displayList();

    l1.insertNodePos(4, 40);
    l1.displayList();

    l1.deleteNodeStart();
    l1.displayList();

    l1.deleteNodeEnd();
    l1.displayList();

    l1.deleteNodePos(2);
    l1.displayList();
}