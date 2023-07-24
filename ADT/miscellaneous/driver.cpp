#include<iostream>
#include "./complex.h"
#include "./point.h"

using namespace std;
using namespace adt;

int main()
 {
	point p1(1,2,1), p2(1,2,-1);
	cout<<(p1&p2);
 	return 0;
 }