#include<iostream>
#include "./complex.h"
#include "./point.h"

using namespace std;
using namespace adt;

int main()
 {
	point p1(0,1,0), p2(1,0,-1);
	cout<<(p1&p2);
	cout<<p1+p2;
 	return 0;
 }