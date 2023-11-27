#include<iostream>
#include "./location.h"
#include "./point.h"

using namespace std;

int main() {

    location l1, l2(1,1, "wall");

    cout<<l2.retloc()._2D();
    return 0;
}