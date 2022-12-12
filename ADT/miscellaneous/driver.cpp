#include<iostream>
#include "C:\\Github\\Abstract-Data-Structures\\ADT\\miscellaneous\\complex.h"

using namespace std;

int main()
 {
 	complex c1 {1,2};
 	//c1.change(2,true);
 	cout<<c1;
	cout<<endl;

	complex c2 {1, 3};
	cout<<c1/c2;
	
	cout<<endl<<c1[1];
 	return 0;
 }