//circular singly linked list

#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class list
{
    node *head, *last;

    node* readnode(int data)
    {
        node* newnode = new node;
        if(newnode == NULL)
         {
            cout<<"\nMemory insufficient! Restart program.";
            exit(0); //exit out of program.
         }
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }


    public:
        list()
         {
             head = last = NULL;
         }

        list(int data)
         {
             head = last = readnode(data);
         }

        int size(); //enumerate the size of the linked list
        bool isEmpty(); //check if linked list empty
        void Empty(); //empty the linked list
        
};
