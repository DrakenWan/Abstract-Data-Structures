#include<iostream>
#include "./point.h"
#include "./location.h"

using namespace std;

int main() {

    point p1(1,2,3.001), p2(1,2,5.002030091);
    p1 = p2;
    cout<<p1;

    location l1(1, 2, 3, "Wall");
    location l2("Wall");
    cout<<l1;
    cout<<l2;

    int R=5, C=5;
    
    return 0;   
}