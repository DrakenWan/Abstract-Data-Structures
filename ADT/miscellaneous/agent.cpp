#include<iostream>
#include "point.h"

using namespace std;

class agent {
    string name;
    point location;

    public:
    agent() {
        this->name = "Agent";
        point loc(0,0);
        this->location = loc;
    }

    agent(double x, double y) {
        this->name = "Agent";
        point loc(x,y);
        this->location = loc;
    }

    agent(string name, double x, double y) {
        this->name = name;
        point loc(x,y);
        this->location = loc;
    }

    agent(point loc) {
        this->name = "Agent";
        this->location = loc;
    }

    agent(string name, point loc) {
        this->name = name;
        this->location = loc;
    }


    string _name() {return this->name;}
    point _location() {return this->location;}

    void moveNorth(int stride=1) {
        location.update(location._y() + stride,1);
    }

    void moveEast(int stride=1) {
        location.update(location._x() + stride,0);
    }

    void moveSouth(int stride=1) {
        location.update(location._y() - stride,1);
    }

    void moveWest(int stride=1) {
        location.update(location._x() - stride,0);
    }

    friend ostream& operator<<(ostream& os,  agent a);

};


ostream& operator<<(ostream& os, agent a)
{
    os<<"[";
    os<<"name: "<<a._name()<<", ";
    os<<"location: ";
    os<<a._location()<<"]";
}

int main() {

    agent a("Anya", 2, 3);
    cout<<a;
    return 0;
}