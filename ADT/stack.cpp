/*
/////////////////// STACK IMPLEMENTATION //////////////////////
Date: 6/18/2019
Author: Kartikay Kaul

////////////////// +++++++++++++++++++++ //////////////////////
 */
#include<iostream>
#include<vector>

using namespace std;

template <typename S>
class stack {
    vector<S> content;
    int length;
    public:
        stack() {
            length = content.size();
        }
        stack(S value)
        {
            content.push_back(value);
        }

        void push(S value);
        S pop();
        S peek();
};

template <typename S>
void stack<S>::push(S value)
{
    try {
        content.push_back(value);
        length = content.size();
    } catch(std::exception e)
    {
        cout<<"Error! Memory overflow!";
    }
}

template <typename S>
S stack<S>::pop()
 {
          if(length != 0)
          {
            S value = content.back();
            content.pop_back();
            length = content.size(); 
            return value; 
          }
          cout<<"\nStack underflow.\n";
          return -1;

}

template <typename S>
 S stack<S>::peek()
 {
     if(length != 0)
        return content[length - 1];
     else {
         cout<<"\nStack Empty\n";
         return -1;
     }
 }

int main()
{
    
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop();
    cout<<s1.peek()<<endl;
    s1.push(25);
    cout<<s1.peek();
    return 0;
}