#include<cmath>
#define index int

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
            this->x = this->y = this->z = 0;
        }

        point(double x, double y) { //2d point
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


        point(double x, double y, double z) { //3d point
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

        bool isOrigin() {if(this->x==0&&this->y==0&&this->z==0) return true; //check if the point is origin
        return false;}

        //return value of components
        double _x() {return this->x;}
        double _y() {return this->y;}
        double _z() {return this->z;}

        //update components
        void update(double data, index i);

        // operations arithmetic
        point operator+(point p1);
        point operator+(double number);
        point operator-(point p1);
        point operator*(double scalar);


        // operations relational

        //advice: do not forget to wrap the objects with small brackets when using << operator to display the results else it creates an error.
        bool operator==(point p1); //compares distances between the points
        bool operator<(point p1); //compares distances from origin between the points
        bool operator>(point p1); //compares distances from origin between the points

        // operations display
        friend ostream& operator<<(ostream& os, const point& p); //display  DS through ostream


        // Other methods
        double distance(point p); //calculate euclidean distance between the points
};

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


void point::update(double data, index i){
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


bool point::operator==(point p1) {
    if( this->distance(p1) == 0 )
        return true;
    return false;
}