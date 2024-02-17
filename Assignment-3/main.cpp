#include <iostream>
#include "./include/linkedlist.h"

int main()
{
    //LinkedList<int> l1;
    LinkedList<int> l1{ 20, 30 };
    l1.displayList();
    std::cout << l1.getLength() << '\n';
    
    l1.insertNodeStart(10);
    l1.displayList();
    std::cout << l1.getLength() << '\n';
    
    l1.insertNodeEnd(50);
    l1.displayList();
    std::cout << l1.getLength() << '\n';

    l1.insertNodePos(4u, 40);
    l1.displayList();
    std::cout << l1.getLength() << '\n';

    l1.deleteNodeStart();
    l1.displayList();
    std::cout << l1.getLength() << '\n';

    l1.deleteNodeEnd();
    l1.displayList();
    std::cout << l1.getLength() << '\n';

    l1.deleteNodePos(2);
    l1.displayList();
    std::cout << l1.getLength() << '\n';

    /*std::cout << "----------------------" << '\n';
    LinkedList<float> l2{ 1.5, 3.0};
    l2.displayList();

    l2.insertNodeStart(0.05);
    l2.displayList();

    l2.deleteNodeEnd();
    l2.displayList();

    l2.deleteNodeStart();
    l2.displayList();

    l2.deleteNodePos(1);
    l2.displayList();

    std::cout << "----------------------" << '\n';
    LinkedList <std::string> l3{ "abc", "def" };
    l3.displayList();

    l3.insertNodeStart("nhd");
    l3.displayList();

    l3.deleteNodeEnd();
    l3.displayList();

    l3.deleteNodeStart();
    l3.displayList();

    l3.deleteNodePos(1);
    l3.displayList();*/
}