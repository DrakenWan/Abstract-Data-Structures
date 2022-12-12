#include<iostream>
#include "C:\\Github\\Abstract-Data-Structures\\ADT\\miscellaneous\\complex.h"

using namespace std;

int main()
 {
 	complex c1 {0,1};
 	//c1.change(2,true);
 	cout<<c1;
	cout<<endl;

	complex c2 {-2, 1};
	cout<<c1*c2;
 	return 0;
 }