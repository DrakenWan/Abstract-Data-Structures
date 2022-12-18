#include<iostream>
#include "point.h"

class agent {
    point location;
};

int main() {

    point p1, p2(3,-1,1);
    int x=3;

    cout<<p1+p2; 
    point p3 = p1 + 1; // adding a scalar to all components of the point
    cout<<p3.isOrigin(); // is it an origin point?

    cout<<endl;
    cout<<p3*x; //multiply a scalar to the point

    cout<<p3.distance(p1+1);
    cout<<endl;
    cout<<"p1+1 and p3 ";
    cout<<((p3 == p1+1)? "equal" : "not equal");

    point p4(1, 20, 5);

    cout<<endl;
    cout<<p4<<endl;
    p4.update(3, 2);
    cout<<endl<<p4;

    point p5(1,1,2);

    cout<<endl<<(p4>p5);
    return 0;
}