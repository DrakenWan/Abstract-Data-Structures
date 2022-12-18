#include<iostream>
#include<cmath>

using namespace std;

class point {
    /*
        A 3D or 2D point in space.
    
    */
    double x, y, z;
    bool is2D, _isOrigin_;

    public:
        point() {
            this-> _isOrigin_ = true;
            this->is2D = false;
            this->x = this->y = this->z = 0;
        }

        point(double x, double y) {
            if(x==0 && y==0)
                point();
            else {
                this->x = x;
                this->y = y;
                this->z = 0;
                this-> _isOrigin_ = this->isOrigin();
            }

            this->is2D = true;
        }


        point(double x, double y, double z) {
            if(x==0 && y==0 && z==0)
                point();
            else {
                this->x = x;
                this->y = y;
                this->z = z;
                this-> _isOrigin_ = this->isOrigin();
            }
            this->is2D = false;
        }

        bool isOrigin() {if(this->x==0&&this->y==0&&this->z==0) return true;
        return false;}


        // operations arithmetic
        point operator+(point p1);
        point operator+(double number);
        point operator-(point p1);
        point operator*(double scalar);

        // operations display
        friend ostream& operator<<(ostream& os, const point& p); //display  DS through ostream


        // Other methods
        double distance(point p); //calculate euclidean distance between the points
};


double point::distance(point p) {
    return sqrt(pow(p.x - this->x, 2) + pow(p.y - this->y, 2) + pow(p.z - this->z, 2));
}

ostream& operator<<(ostream& os, const point& p) {
    os<<'('<<p.x<<','<<p.y;

    if(p.is2D == false) os<<','<<p.z;

    os<<')';
}


point point::operator+(double number) {
    point p;
    p.x = number + this->x;
    p.y = number + this->y;
    p.z = number + this->z;

    return p;
}

point point::operator+(point p1) {
    point p;
    p.x = this->x + p1.x;
    p.y = this->y + p1.y;
    p.z = this->z + p1.z;

    return p;
}


point point::operator-(point p1) {
    point p;
    p.x = this->x - p1.x;
    p.y = this->y - p1.y;
    p.z = this->z - p1.z;

    return p;
}


point point::operator*(double scalar) {
    point p;
    p.x = scalar * (this->x);
    p.y = scalar * (this->y);
    p.z = scalar * (this->z);

    return p;
}


class agent {
    point location;
};

int main() {

    point p1, p2(3,-1,1);
    int x=3;

    cout<<p1+1; 
    point p3 = p1 + 1; // adding a scalar to all components of the point
    cout<<p3.isOrigin(); // is it an origin point?

    cout<<endl;
    cout<<p3*x; //multiply a scalar to the point
    
    return 0;
}