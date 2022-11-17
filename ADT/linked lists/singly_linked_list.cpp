/* Singly Linked List implementation in C++ 
  By Karry Kaul
*/
#include<iostream>
#include "./singlylinkedlist.h"
using namespace std;


int main()
{
    list<int> l1;
    cout<<l1.size()<<endl;
    //l1.create();
    l1.insertLast(10);
    l1.insertFirst(2);
    //cout<<l1.size()<<endl;
    l1.insertMiddleAfterX(10,65);
    //cout<<l1.size()<<endl;
    l1.insertMiddleCount(0,11);
    //cout<<l1.size()<<endl;

    l1.display();
    // l1.delFirst();
    // l1.delLast();
    // l1.display();
    //l1.create();
    //l1.Empty();

    // if(l1.isEmpty())
    //     cout<<"\nEmpty!";
    // else
    //    cout<<"\nNein Empty";

    // list<float> l2;
    // l2.create();
    // l2.display();

    // cout<<"End of werk\n";
    // list<string> l3;
    // l3.create();
    // l3.display();

    list<int> l2;
    l2.insertLast(-1);
    l2.insertFirst(0);
    l2.insertLast(10);
    l2.insertLast(22);
    l2.insertLast(33);
    l2.display();
    list<int> l3 = l1 + l2;
    
    l3.display();
    return 0;
}
