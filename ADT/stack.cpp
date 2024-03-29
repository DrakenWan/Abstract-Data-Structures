/*
/////////////////// STACK IMPLEMENTATION //////////////////////
Date: 6/18/2019
Author: Kartikay Kaul

////////////////// +++++++++++++++++++++ //////////////////////
 */
#include<iostream>
#include<vector>
#include<typeinfo>
#include "stack.h"

using namespace std;


int main()
{
    /*
        Run a stack implementation of any datatype below: be it string int or an object instance itself
        stack<datatype> instancevariablename
        You can experiment below with different methods of the object instance
     */
    
    stack<int> s1;
    s1.push(1);
    cout<<s1.peek();
    s1.push(10);
    s1.push(-1);
    s1.toString();
    
    stack<string> s2;
    s2.push("neeta");
    s2.push("sahil");
    s2.push("ike");
    s2.push("camila");
    s2.push("noora");
    s2.toString();
    cout<<s2.StackLength();
    s2.pop();
    s2.toString();
    cout<<s2.StackLength();
    cout<<endl<<endl<<"new new new";
    stack<int> s3;
    s3.push(69);
    s3.toString();
    cout<<s3.peek();
    cout<<s3.pop();
    s3.toString();

    return 0;
}
