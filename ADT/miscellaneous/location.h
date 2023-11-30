#pragma once
#include "./point.h"
#include "./String.h"
#include<iostream>
# define StringType String

class location {
    
    long id;
    point loc;
    StringType type;
    
    
    static long num;

    public:
        
        location() {
            this->id = ++num;
            this->loc = point(0,0);
            this->type = "None";
        }

        location(point p1, StringType type) {
            this->id = ++num;
            this->loc = p1;
            this->type = type;
        }

        location(point p1) {
            this->id = ++num;
            this->loc = p1;
            this->type = "None";
        }
        
        location(double x, double y, double z) {
            this->id = ++num;
            this->loc = point(x, y, z);
            this->type = "None";
        }

        location(double x, double y) {
            this->id = ++num;
            this->loc = point(x,y);
            this->type = "None";
        }

        location(double x, double y, double z, StringType type) {
            this->id = ++num;
            this->loc = point(x, y, z);
            this->type = type;
        }

        location(double x, double y, StringType type) {
            this->id = ++num;
            this->loc = point(x, y);
            this->type = type;
        }

        location(StringType type) {
            this->id = ++num;
            this->loc = point(0,0);
            this->type = type;
        }

        // return the location dim in 2d/3d space as a point
        point retloc() {
            return this->loc;
        }

            
        void updateLocDim(double,int);
        void updateLocType(StringType);
        void updateLocation(point);
        void updateLocation(double, double);
        void updateLocation(double, double, double);

        //relational operators
        bool operator==(location);

        void display() {
            std::cout<<*this;
        }

        // operations display
        friend ostream& operator<<(ostream& os, location& l); //display  DS through ostream

};

long location::num=0;

// == 
bool location::operator==(location l1) {
    if(this->loc == l1.loc)
        return true;
    return false;
}

// update locations
void location::updateLocDim(double data, int index) {
    this->loc.update(data, index);
}

void location::updateLocation(double x, double y, double z) {
    this->loc.update(x, 0);
    this->loc.update(y, 1);
    this->loc.update(z, 2);
}

void location::updateLocation(double x, double y) {
    this->loc.update(x, 0);
    this->loc.update(y, 0);
}


// update location type
void location::updateLocType(StringType type) {
    this->type = type;
}

// << ostream overloading
ostream& operator<<(ostream& os, location& l) {
    os<<"\n[(location)id: "<<l.id<<",\n"
      <<"location: "<<l.loc<<",\n"
      <<"type: "<<l.type<<"]\n";

      return os;
}