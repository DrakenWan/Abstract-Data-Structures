/* Singly Linked List implementation in C++ 
  By Karry Kaul
*/
#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class list
{
    node *head;
    node *last;

    //declared as private
    node* readnode(int data)
    {
        node* newnode = new node;
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

         list(int data)
         {
             head = last = readnode(data);
         }

        int isEmpty();
        void Empty();
        int size();
        int create();
        int insertLast(int data);
        int insertFirst(int data);
        int insertMiddleAfterX(int x, int data);
        int insertMiddleCount(int count, int data);

        int delFirst();
        int delLast();
        //int delData(int data); //will add later
        void display();
};

void list::Empty()
 {
     head=last=NULL; 
 }

int list::isEmpty()
 {
     if(this->size()==0)
        return 1;
    else
        return 0;
 }

int list::size()
 {
     int counter=0;
     node* traverse = head;
     while(traverse != NULL)
      {
       counter++;
       traverse = traverse->next;
      }
    return counter;
 }

int list::create()
{
    int c,data;
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
int list::insertLast(int data=0)
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

int list::insertFirst(int data=0)
{
    if(head == NULL)
      {
        head=last=readnode(data);
        return 1;
      }
    node* newnode = readnode(data);
    newnode->next = head;
    head=newnode;
    return 1;
}//end of insertLast

//insert middle after the data given
int list::insertMiddleAfterX(int x, int data)
{
    node* newnode = readnode(data);
    
    node *temp = head;
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
int list::insertMiddleCount(int count, int data)
{
    if(head == NULL)
         head = last = readnode(data);

     
     node *temp = head;
     while(count>0 && temp!=NULL)
     {
         temp = temp->next;
         count--;
     }
    if(this->size() > count)
    {
      node* newnode = readnode(data);
      newnode->next = temp->next;
      temp->next = newnode;
      if(temp == last)
       last = newnode; 
      return 1;
    }
    return 0;
}//Insert Middle After count ends

//delFirst() Method
int list::delFirst()
{
    if(head == NULL)
     {
         cout<<"\nLinked list empty.";
         return -1;
     }
     else
     {
         node *delnode = head;
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
int list::delLast()
{
    if(head==NULL)
    {
        cout<<"\nLinked list is empty.";
        return -1;
    }
    else
    {
        node* delnode = last;
        cout<<"\nDeleted node is "<<delnode->data;
        if(head == last)
            head=last=NULL;
        else
        {
            node* t = head;
            node* prev = new node;
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

void list::display()
{
    if(head==NULL)
        cout<<"\nLinked list is empty.";
    else
    {
        node* t = head;
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
    list l1;
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
    l1.create();
    //l1.Empty();

    if(l1.isEmpty())
        cout<<"\nKhatam!";
    else
        cout<<"\nNahi Khatam!";
    return 0;
}
