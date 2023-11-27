#pragma once
#include "./point.h"
#include<iostream>

class location {
    
    long id;
    point xy;
    std::string type;
    
    
    static long num;

    public:
        
        location() {
            this->id = ++num;
            this->xy = point(0,0);
            this->type = "None";
        }

        point retxy() {
            return this->xy;
        }

        
        void display() {
            std::cout<<this;
        }

        // operations display
        friend ostream& operator<<(ostream& os, location& l); //display  DS through ostream

};

long location::num=0;

ostream& operator<<(ostream& os, location& l) {
    os<<"[(location)id: "<<l.id<<",\n"
      <<"location: "<<l.xy<<",\n"
      <<"type: "<<l.type<<"]\n";
}