/* Singly Linked List implementation in C++ 
  By Karry Kaul
*/
#include<iostream>

using namespace std;

template <typename any>
struct node
{
    any data;
    node<any>* next;
};

template <typename any>
class list
{
    node<any> *head;
    node<any> *last;

    //declared as private
    node<any>* readnode(any data)
    {
        node<any>* newnode = new node<any>;
        if(newnode == NULL)
        {
            cout<<"Memory insufficient!";
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

         list(any data)
         {
             head = last = readnode(data);
         }

        int isEmpty(); //is the linked list empty
        void Empty(); // clear the entire list
        int size(); //enumerate the 
        int create();
        int insertLast(any data);
        int insertFirst(any data);
        int insertMiddleAfterX(any x, any data);
        int insertMiddleCount(int count, any data);

        int delFirst();
        int delLast();
        //int delData(any data); //will add later
        void display();
};

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

template <typename any>
int list<any>::create()
{
    int c;
    any data;
    if(head!=NULL)
    {
        cout<<"\nLinked list already created.";
        return -1;
    }
    else
    {
        do
        {
            cout<<"\nEnter the data element:";
            cin>>data;
            if(head == NULL)
            {
                head=last=readnode(data);
            }
            else
            {
                last->next = readnode(data);
                last = last->next;
            }

            cout<<"\nEnter 1 to add another node: "; cin>>c;
        }while(c==1);
    }

    return 1;
}//end of create method

//INSERT LAST METHOD
template <typename any>
int list<any>::insertLast(any data)
{
    if(head == NULL)
    {
        head = last = readnode(data);
        return 1;
    }

    last->next = readnode(data);
    last = last->next;
    return 1;
}//end of insertLast method

template <typename any>
int list<any>::insertFirst(any data)
{
    if(head == NULL)
      {
        head=last=readnode(data);
        return 1;
      }
    node<any>* newnode = readnode(data);
    newnode->next = head;
    head=newnode;
    return 1;
}//end of insertLast

//insert middle after the data given
template <typename any>
int list<any>::insertMiddleAfterX(any x, any data)
{
    node<any>* newnode = readnode(data);
    
    node<any> *temp = head;
    while(temp!=NULL)
    {
        if(temp->data == x)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            if(temp == last)
                last = newnode;
            return 1;
        }
        else
        {
            temp = temp->next;
        }
    }
    return 0;    
}//insert middle after the data ends

// Method for Insert Middle after Count
template <typename any>
int list<any>::insertMiddleCount(int count, any data)
{
    if(head == NULL)
         head = last = readnode(data);

     
     node<any> *temp = head;
     while(count>0 && temp!=NULL)
     {
         temp = temp->next;
         count--;
     }
    if(this->size() > count)
    {
      node<any>* newnode = readnode(data);
      newnode->next = temp->next;
      temp->next = newnode;
      if(temp == last)
       last = newnode; 
      return 1;
    }
    return 0;
}//Insert Middle After count ends

//delFirst() Method
template <typename any>
int list<any>::delFirst()
{
    if(head == NULL)
     {
         cout<<"\nLinked list empty.";
         return -1;
     }
     else
     {
         node<any> *delnode = head;
         cout<<"\nDeleted node is "<<delnode->data;
         if(head == last)
            head=last=NULL;
        else
            head = head->next;
         delete delnode;
         return 0;
     }
}//delFirst() Method Ends here

//delLast() Method
template <typename any>
int list<any>::delLast()
{
    if(head==NULL)
    {
        cout<<"\nLinked list is empty.";
        return -1;
    }
    else
    {
        node<any>* delnode = last;
        cout<<"\nDeleted node is "<<delnode->data;
        if(head == last)
            head=last=NULL;
        else
        {
            node<any>* t = head;
            node<any>* prev = new node<any>;
            while(t->next != NULL)
            {
                prev = t;
                t = t->next;
            }
            last = prev;
            last->next=NULL;
            delete t;            
        }
        return 1;
    }
}//delLast() Method ends here

template <typename any>
void list<any>::display()
{
    if(head==NULL)
        cout<<"\nLinked list is empty.";
    else
    {
        node<any>* t = head;
        cout<<endl;
        while(t != NULL)
         {
             cout<<t->data;
             if(t->next != NULL) cout<<" => "; //if not last node form a link
             t = t->next;
         }
    }
}

int main()
{
    list<int> l1;
    cout<<l1.size()<<endl;
    //l1.create();
    l1.insertLast(10);
    l1.insertFirst(2);
    cout<<l1.size()<<endl;
    l1.insertMiddleAfterX(10,65);
    cout<<l1.size()<<endl;
    l1.insertMiddleCount(0,11);
    cout<<l1.size()<<endl;

    l1.display();
    l1.delFirst();
    l1.delLast();
    l1.display();
    //l1.create();
    //l1.Empty();

    if(l1.isEmpty())
        cout<<"\Empty!";
    else
        cout<<"\nNein Empty";

    list<float> l2;
    l2.create();
    l2.display();

    cout<<"End of werk\n";
    list<string> l3;
    l3.create();
    l3.display();

    return 0;
}
