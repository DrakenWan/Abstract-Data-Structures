#include<iostream>
#include "point.h"

using namespace std;

class agent {
    
    // base attributes
    string name;
    point location;


    // other attributes
    double weight;

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

    // return values of attributes
    string _name() {return this->name;}
    point _location() {return this->location;}
    double _weight() {return this->weight;}


    // movement functions
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


    // set attribute functions
    void setWeight(double weight) { this->weight = weight;}
    void setLocation(double x, double y) { 
        this->location.update(x, 0); 
        this->location.update(y, 1);
    }
    void setLocation(point p) {
        this->location = p;
    }
    void changeName(string name) {this->name = name;}
    

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
    agent b("Keri", 2, 4);
    agent c ("Natu", 1, 3);
    cout<<a<<endl<<b<<endl<<c;
    return 0;
}