#include<iostream>
#include "list.h"

using namespace std;

int main() {

    list<int> l1;
    l1.create();
    l1.display();
    l1.insertAtFront(10);
    l1.insertAtFront(20);
    l1.insertAtFront(30);
    l1.display();
    return 0;
}