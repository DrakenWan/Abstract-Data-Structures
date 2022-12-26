#include<iostream>
#include "./complex.h"

using namespace std;
using namespace adt;

int main()
 {
 	complex c1 {1,2};
 	//c1.change(2,true);
 	cout<<c1;
	cout<<endl;

	complex c2 {1, 3};
	cout<<c1/c2;
	
	cout<<endl<<c1[1];
	cout<<endl;
	cout<<c1;
	complex c3 {1,2}, c4{0,2};
	if(c3 == c4) {
		cout<<endl;
		cout<<c3;
		cout<<" and ";
		cout<<c4;
		cout<<" are equal.";
	} else {
		cout<<"\nnot equal.";
	}


	complex c10(10,20);
	cout<<endl<<c10;
	c10[0] = 1;
	cout<<endl<<c10;

	cout<<endl<<endl;

	complex c11(1,-2), c12(2,-1);
	cout<<(c11/c12);
	cout<<endl<<(c11+1);
 	return 0;
 }