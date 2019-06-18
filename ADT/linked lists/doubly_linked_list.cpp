/* Doubly Linked List Implementation
   By Karry Kaul
*/
#include<iostream>

using namespace std;

//each doubly linked list node
template <typename any>
struct node
{
    any data;
    node<any>* prev;
    node<any>* next;
};

//class list to define our linked list
//and establish its behaviour/functionalities
template <typename any>
class list
{
    node<any>* head;
    node<any>* last;

    //declared as private
    node<any>* readnode(int data)
     {
         node<any>* newnode = new node<any>;
         if(newnode == NULL)
            {
                cout<<"Insufficient Memory!";
                exit(0);
            }
         newnode->data = data;
         newnode->prev = NULL;
         newnode->next = NULL;
         return newnode;
     }

    public:
    list()
     {
         head = last = NULL;
     }
     list(any data)
     {
         head = last = readnode(data);
     }
     
     int size(); //enumerate the size of the list
     int isEmpty(); //check if empty
     void Empty(); //empty the list
     int create();
     int insertLast(any data);
     int insertFirst(any data);

     //below Middle Traversals are from head to last.
     int insertMiddleAfterX(any x, any data); //insert data after X element
     int insertMiddleAfterCount(int count, any data); //insert after traversing Count
     // number of nodes
     
     int delFirst();
     int delLast();
     int delData(int data);
     //display
     //forward Traversal
     void display(int t=0);
};//end of class LIST

template <typename any>
void list<any>::Empty()
 {
     head=last=NULL; 
 }

template <typename any>
int list<any>::isEmpty()
 {
     if(this->size()==0)
        return 1;
    else
        return 0;
 }

template <typename any>
int list<any>::size()
 {
     int counter=0;
     node<any>* traverse = head;
     while(traverse != NULL)
      {
       counter++;
       traverse = traverse->next;
      }
    return counter;
 }

//create method
template <typename any>
int list<any>::create()
{
  int c;
  any data;
  if(head != NULL)
  {
      cout<<"\nlinked list was already created with some entries.";
      return -1;
  }
  else
  {
      do
       {
           cout<<"\nEnter the data: "; cin>>data;
           if(head == NULL)
            head = last = readnode(data);
           else
            {
                node<any>* newnode = readnode(data);
                last->next = newnode;
                newnode->prev = last;
                last = last->next;
            }
            cout<<"Press 1 to add another node: "; cin>>c;
       }while(c==1);
  }//else condition of create
  return 1;
}//end of create method

//insertLast method
template <typename any>
int list<any>::insertLast(any data)
{
    if(head == NULL)
        head = last = readnode(data);
    else
     {
        node<any>* newnode = readnode(data);
        last->next = newnode;
        newnode->prev = last;
        last = last->next; //or last = newnode can do as well.
     }
     return 1;
}//insertLast method ends here

//insertFirst method
template <typename any>
int list<any>::insertFirst(any data)
{
    if(head == NULL)
        head = last = readnode(data);
    else
    {
        node<any>* newnode = readnode(data);
        head->prev = newnode;
        newnode->next = head;
        head = head->prev; //or head = newnode can do as well
    }
    return 1;
}//insertLast method ends here

//insertMiddleAfterX method
template <typename any>
int list<any>::insertMiddleAfterX(any x, any data)
{
    //if x is the last node then there will be no insertion
    node<any>* newnode = readnode(data);
    node<any>* temp = head;
    while(temp != NULL)
     {
        if(temp->data == x && temp->next != NULL)
        {
            //under testing
            node<any>* next = temp->next;
            newnode->next = next;
            temp->next = newnode;
            next->prev = newnode;
            newnode->prev = temp;
            return 1;
        }
        else
        {
          temp = temp->next;
        }
     }
    return -1;
}//insertMiddleAfterX method ends here

template <typename any>
int list<any>::delFirst()
{
    if(this->isEmpty())
        return -1;
    else
    {
        node<any> *delnode = head;
        cout<<"\nDeleted node is "<<delnode->data;
        if(head == last)
            head = last = NULL;
        else
        {
            head = head->next;
            head->prev = NULL;
        }
    }
    return 1;
}//delFirst method ends here

template <typename any>
int list<any>::delLast()
{
    if(this->isEmpty())
        return -1;
    else
    {
        node<any>* delnode = last;
        cout<<"\nDeleted node is "<<delnode->data;
        if(head==last)
            head=last=NULL;
        else
        {
            last = last->prev;
            last->next = NULL;
        }
    }
    return 1;
}//delLast method ends here

//delData method starts here
template <typename any>
int list<any>::delData(int data)
{
    //return -1 : list is empty
    //return 0 : could not find the data element to be deleted
    //return 1 : deleted successfully
    node<any>* delnode = head;
    if(head == NULL)
        return -1;
    else
    {
        while(delnode!=NULL)
        {
            if(delnode->data == data)
            {
               if(delnode == head)
                this->delFirst();
               else if(delnode == last)
                this->delLast();
               else
               {
                   cout<<"\nDeleted node is: "<<delnode->data;
                   node<any>* prev = delnode->prev;
                   node<any>* next = delnode->next;
                   prev->next = next;
                   next->prev = prev;
                   delete delnode;
               }
               return 1;
            }
            else
            {
                delnode = delnode->next;
            }
            
        }
    }
    return 0;
}//delData method ends here

template <typename any>
void list<any>::display(int t)
{
    if(this->isEmpty())
        {
            cout<<"\nThe list is empty.";
            return;
        }

    //t == 0 : forward traversal
    //t == 1 : backward traversal
    cout<<endl;
    node<any>* temp = new node<any>;
    if( t == 0)
    //forward traversal
    {
        temp = head;
        while(temp!=NULL)
         {
             cout<<temp->data;
             if(temp->next != NULL) cout<<" => ";
             temp = temp->next;
         }
    }
    else
    //backward traversal
    {
        temp = last;
        while(temp!=NULL)
         {
             cout<<temp->data;
             if(temp->prev != NULL) cout<<" => ";
             temp = temp->prev;
         }
    }
          
}//display method ends here

int main()
{
    int after, val = 10;
    list<int> l1(val);
    val = 2;
    l1.insertFirst(val);
    val=12;
    l1.insertLast(val);
    val = 40; after = 12;
    if(l1.insertMiddleAfterX(12,40) == -1)
        cout<<"\nInsertion of "<<val<<" after "<<after<<" failed.\n";
    val=20;
    l1.insertLast(val);
    val=-10;
    l1.insertFirst(val);
    l1.display();
    l1.display(1);
    l1.delFirst();
    l1.delFirst();
    l1.delLast();
    l1.display();
    return 0;
}
