#pragma once
#include<vector>

template<typename S>
class stack {
    std::vector<S> content;
    int length;
    public:
        stack() {
            this->length = content.size();
        }
        stack(S value)
        {
            this->push(value);
        }

        void push(S value);
        int StackLength() {return this->length;}
        void clear();
        void toString();
        S pop(bool verbose=false);
        S peek();
};

template <typename S>
void stack<S>::push(S value)
{
    /*
        Push above the top of the stack
     */
    try {
        this->content.push_back(value);
        this->length = content.size();
    } catch(std::exception e)
    {
        std::cout<<"Error! Memory overflow!";
    }
}

template <typename S>
S stack<S>::pop(bool verbose)
 {
    /*
        Pop the top element of the stack
     */
    if(length != 0)
    {
    S value = this->content.back();
    if(verbose) std::cout<<"Deleted content value: "<<value;
    this->content.pop_back();
    this->content.shrink_to_fit(); //this will shrink the size //pop_back alone doesn't shrink the size
    this->length = content.size(); 
    return value; 
    } else {
        throw std::underflow_error("Stack underflow.\n");
    }
    
}

template <typename S>
 S stack<S>::peek()
 {
     /*
        Peek the top of the stack
      */
     if(this->length != 0)
        {
            S value = this->content.back();
            return value;
        }
     else {
         std::cout<<"\nStack Empty\n";
         S value;
         return value;
     }
 }

template <typename S>
void stack<S>::clear()
{
    /*
        Clear the stack contents
     */

    if(this->length != 0)
    {
        while(this->length != 0)
        {
            this->pop();
        }
        std::cout<<"Stack cleared.\n";
    }
    else
    {
        std::cout<<"Stack is already clear.\n";
    }
    
}

template <typename S>
void stack<S>::toString()
{
    /*
        shows string representation of the internal contents
     */

    std::cout<<"\n[";
    for(int i=0; i<length; i++)
    {
        if(i != length - 1)
            std::cout<<this->content[i]<<"->";
        else
            std::cout<<this->content[i]<<"(top)";
    }
    if(this->length == 0) std::cout<<"(empty)";
    std::cout<<"]\n";
}