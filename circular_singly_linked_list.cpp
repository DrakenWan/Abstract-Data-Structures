/*circular singly linked list
//author: Kartikay Kaul
//Future ideas:
    ╤ add a method to return a node with traversal almost like a search function

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
             last->next = head;
         }

        int size(); //enumerate the size of the linked list
        bool isEmpty(); //check if linked list empty
        void Empty(); //empty the linked list

        //insertion or creation methods follow below
        int create();
        int insertFirst(int data);
        int insertLast(int data);
        int insertMiddleAfterX(int x, int data);
        int insertMiddleAfterCount(int count, int data);

};

//size method
int list::size()
 {
     int count=1;
     if(head == NULL) //directly checking if head is NULL or not
        return 0;
     else
     {
         node* temp = head;
         while(temp->next != head)
            {
                count++;
                temp = temp->next;
            }
     }
    return count;
 }//size method ends

//isEmpty method begins
bool list::isEmpty()
 {
     if(this->size() == 0)
        return true;
    else
        return false;
 }//isEmpty method ends here

//Empty method : to empty the list
void list::Empty()
 {
     if(head == NULL)
        cout<<"\nthe list is already empty.";
     
     head = last = NULL;
 }//Empty method ends here


//create function
int list::create()
 {
     int c, data;
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
int list::insertFirst(int data)
{
    if(head == NULL)
       head = last = readnode(data);
    else
    {
        node* newnode = readnode(data);
        newnode->next = head;
        head = newnode;
    }
    last->next = head;
    return 1;
}//inserFirst Method ends here
 
//insertLast method
int list::insertLast(int data)
{
    if(head == NULL)
        head = last = readnode(data);
    else
    {
        node* newnode = readnode(data);
        last->next = newnode;
        last = newnode; 
    }
    last->next = head;
    return 1;
}//insertLast method ends here

//insertAfterX Method
int list::insertMiddleAfterX(int x, int data)
{
    node* newnode = readnode(data);
    if(head == NULL)
        return -1;
    else
    {
        node* temp = head;
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
      list l1(10);
      list l2;
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
