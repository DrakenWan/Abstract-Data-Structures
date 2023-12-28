#pragma once
#include<stdexcept>
#include<cmath>

using namespace std;

class point {
    /*
        A 3D or 2D point in space.
    
    */
    double x, y, z;
    bool is2D, _isOrigin_;

    public:
        point() { //3d point at origin
            this-> _isOrigin_ = true;
            this->is2D = false;
            this->x = this->y = this->z = 0.;
        }

        point(double x, double y) { //2d point
            this->x = x;
            this->y = y;
            this->z = 0.;
            this-> _isOrigin_ = this->isOrigin();

            this->is2D = true;
        }


        point(double x, double y, double z) { //3d point
            this->x = x;
            this->y = y;
            this->z = z;
            this-> _isOrigin_ = this->isOrigin();
            this->is2D = false;
        }

        point(const point &p1) {
            x = p1.x;
            y = p1.y;
            z = p1.z;
            is2D = p1.is2D;
            _isOrigin_ = p1._isOrigin_;
        }

        bool isOrigin() {if(this->x==0.&&this->y==0.&&this->z==0.) return true; //check if the point is origin
        return false;}

        //check if 2d
        bool _2D() {
            return is2D;
        }

        //return value of components
        double const _x() {return this->x;}
        double const _y() {return this->y;}
        double const _z() {return this->z;}

        //update components
        void update(double data, int i);

        // operations arithmetic
        point operator+(point p1);
        point operator+(double number);
        point operator-(point p1);
        point operator*(double scalar);
        double operator&(point p1); //dot product


        // operations relational

        //advice: do not forget to wrap the objects with small brackets when using << operator to display the results else it creates an error.
        bool operator==(point p1); //compares distances between the points
        bool operator<(point p1); //compares distances from origin between the points
        bool operator>(point p1); //compares distances from origin between the points


        // assignment operator overload
        void operator=(const point&);

        // operations display
        friend ostream& operator<<(ostream& os, const point& p); //display  DS through ostream

        double& operator[](int idx) {
            switch(idx) {
                case 0 : return this->x;
                case 1 : return this->y;
                case 2 : 
                    if(!this->is2D)
                        return this->z;
                    else
                        throw std::invalid_argument("Not a 3d point.");
                default : 
                    throw std::invalid_argument("Wrong axis index used.");
            }
        }

        double& operator[](char idx) {
            switch(idx) {
                case 'x' : return this->x;
                case 'y' : return this->y;
                case 'z' : 
                   if(!this->is2D)
                        return this->z;
                    else
                        throw std::invalid_argument("Not a 3d point.");
                default : 
                    throw std::invalid_argument("Wrong axis index used.");
            }
        }

        // Other methods
        double distance(point p); //calculate euclidean distance between the points
};

void point::operator=(const point &p1) {
    this->x = p1.x;
    this->y = p1.y;
    this->z = p1.z;
    this->is2D = p1.is2D;
    this->_isOrigin_ = p1._isOrigin_;
}

bool point::operator<(point p1) {
    point origin;
    if (this->distance(origin) < p1.distance(origin)) return true;
    return false;
}

bool point::operator>(point p1) {
    point origin;
    if (this->distance(origin) > p1.distance(origin)) return true;
    return false;
}


void point::update(double data, int i){
    switch(i) {
        case 0 : this->x = data; break;
        case 1 : this->y = data; break;
        case 2 : this->z = data; break;
        default : cout<<"Error. Wrong index. Update failed.";
    }
}

double point::distance(point p) {
    return sqrt(pow(p.x - this->x, 2) + pow(p.y - this->y, 2) + pow(p.z - this->z, 2));
}

ostream& operator<<(ostream& os, const point& p) {
    os<<'('<<p.x<<','<<p.y;

    if(p.is2D == false) os<<','<<p.z;

    os<<')';    

    return os;
}


point point::operator+(double number) {
    point p;
    p.x = number + this->x;
    p.y = number + this->y;
    
    if(this->is2D == false)
        p.z = number + this->z;

    if(this->is2D)
        p.is2D = true;
    
    return p;
}

point point::operator+(point p1) {
    point p;
    p.x = this->x + p1.x;
    p.y = this->y + p1.y;
    p.z = this->z + p1.z;

    if(this->is2D  && p1.is2D)
        p.is2D = true;
    return p;
}


point point::operator-(point p1) {
    point p;
    p.x = this->x - p1.x;
    p.y = this->y - p1.y;
    p.z = this->z - p1.z;

    if(this->is2D && p1.is2D)
        p.is2D = true;

    return p;
}


point point::operator*(double scalar) {
    point p;
    p.x = scalar * (this->x);
    p.y = scalar * (this->y);
    p.z = scalar * (this->z);

    if(this->is2D)
        p.is2D = true;
    return p;
}


bool point::operator==(point p1) {
    point origin;
    if( this->distance(origin) == p1.distance(origin))
        return true;
    return false;
}


double point::operator&(point p1) {
    double sum =  p1.x * this->x + p1.y * this->y +  p1.z * this->z;
    return sum;
}