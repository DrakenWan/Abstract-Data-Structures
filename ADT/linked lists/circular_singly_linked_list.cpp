/*circular singly linked list
//author: Kartikay Kaul
//method functionalities are descriped within function definitions or declarations
// still under construction
//Future ideas:
    ╤ add a method to return a node with traversal almost like a search function

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
    node<any> *head, *last;

    node<any>* readnode(int data)
    {
        node<any>* newnode = new node<any>;
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
             //start off with an empty list
             head = last = NULL;
         }

        list(any data)
         {
             //initialise the list with one element
             head = last = readnode(data);
             last->next = head;
         }

        int size(); //enumerate the size of the linked list
        bool isEmpty(); //check if linked list empty
        void Empty(); //empty the linked list

        //insertion or creation methods follow below
        int create(); //create a list only if it is entirely empty
        int insertFirst(any data); // insert the element at the head of the linked list
        int insertLast(any data); // insert the element at the rear of the linked list
        int insertMiddleAfterX(any x, any data); // insert 'data' after element 'x'
        int insertMiddleAfterCount(int count, any data); // insert 'data' after 'count'th element

};

//size method
template <typename any>
int list<any>::size()
 {
     int count=1;
     if(head == NULL) //directly checking if head is NULL or not
        return 0;
     else
     {
         node<any>* temp = head;
         while(temp->next != head)
            {
                count++;
                temp = temp->next;
            }
     }
    return count;
 }//size method ends

//isEmpty method begins
template <typename any>
bool list<any>::isEmpty()
 {
     if(this->size() == 0)
        return true;
    else
        return false;
 }//isEmpty method ends here

//Empty method : to empty the list
template <typename any>
void list<any>::Empty()
 {
     if(head == NULL)
        cout<<"\nthe list is already empty.";
     
     head = last = NULL;
 }//Empty method ends here


//create function
template <typename any>
int list<any>::create()
 {
     int c;
     any data;
     if(head != NULL)
     {
        cout<<"\nThe list is already created.";
        return -1;
     }
     else
     {
         do
         {
             cout<<"\nEnter the data element: ";
             cin>>data;
             if(head == NULL)
                head = last = readnode(data);
             else
             {
                 last->next = readnode(data);
                 last = last->next;
                 last->next = head; //circular property of our csll
             }
            
            cout<<"\nEnter 1 to add another node: "; cin>>c;
         } while (c==1);
     }  
    return 1;
 }//end of create method

//insertFirst method
template <typename any>
int list<any>::insertFirst(any data)
{
    if(head == NULL)
       head = last = readnode(data);
    else
    {
        node<any>* newnode = readnode(data);
        newnode->next = head;
        head = newnode;
    }
    last->next = head;
    return 1;
}//inserFirst Method ends here
 
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
        last = newnode; 
    }
    last->next = head;
    return 1;
}//insertLast method ends here

//insertAfterX Method
template <typename any>
int list<any>::insertMiddleAfterX(any x, any data)
{
    node<any>* newnode = readnode(data);
    if(head == NULL)
        return -1;
    else
    {
        node<any>* temp = head;
        do
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
        
        } while (temp != head);
    }
  return -1;
}//insertMiddleAfterX method ends here


 int main()
  {
      list<int> l1(10);
      list<int> l2;
      cout<<l1.size()<<endl;
      cout<<l2.size();
      l2.create();
      //l2.create();
      l2.insertFirst(10);
      l2.insertLast(12);
      cout<<l2.size();
      l2.insertMiddleAfterX(12,2);
      cout<<endl<<l2.size();
      return 0;
  }
