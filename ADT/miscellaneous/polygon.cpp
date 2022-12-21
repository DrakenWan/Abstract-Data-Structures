#include<iostream>
#include<vector>
#include "point.h"
using namespace std;


//helper function
double round_to(double value, double precision=1.0, bool precision_index=-1)
{   
    double precisions[] = { 0.001, 0.01, 0.1, 1, 2, 3, 4 };
    if(precision_index != -1) precision=precisions[precision_index];
    
    return std::round(value / precision) * precision;
}


class polygon {
    int n_sides;
    bool regular;
    point centroid;
    double radius;
    vector<point> vertices;

    //auxiliary attribute
    const double pi = 3.14159265358979323846;

    void _initDispMsg_() {
            switch(this->n_sides) {
                case 3 : cout<<"Triangle"; break;
                case 4 : cout<<"Quadrilateral"; break;
                case 5 : cout<<"Pentagon"; break;
                case 6 : cout<<"Hexagon"; break;
                case 7 : cout<<"Septagon"; break;
                case 8 : cout<<"Octagon"; break;
                case 9 : cout<<"Nonagon"; break;
                case 10 : cout<<"Decagon"; break;
                case 11 : cout<<"Hendecagon"; break;
                case 12 : cout<<"Dodecagon"; break;
                case 13 : cout<<"Tridecagon"; break;
                case 14 : cout<<"Tetradecagon"; break;
                case 15 : cout<<"Pendedecagon"; break;
                case 16 : cout<<"Hexdecagon"; break;
                case 17 : cout<<"Heptdecagon"; break;
                case 18 : cout<<"Octdecagon"; break;
                case 19 : cout<<"Enneadecagon"; break;
                case 20 : cout<<"Icosagon"; break;
                default : cout<<"Polygon"; break;
            }

            cout<<" created.\b";
        }

    public:
        polygon() {
            n_sides = 0;
            regular = false;
            point centre(0,0);
            this->centroid = centre;

            cout<<"Polygon with 0 sides initialized.";
        }

        polygon(int n_sides, bool regular=false) {
            try {
                if(n_sides < 3)
                    throw n_sides;
                else {
                    this->n_sides = n_sides;
                    this->regular = regular;
                    point centre(0,0);
                    this->centroid = centre;

                    this->_initDispMsg_();
                }
            } catch(int n) {
                cout<<"Value Error: number of sides is less than 3. Given input = "<<n;
            }
        }

        //set functions
        void setSides(int n_sides){this->n_sides = n_sides;}
        void setRadius(double radius){this->radius = radius;}
        void setCentroid(point centre){this->centroid = centre;}
        void setCentroid(double x, double y) {
            point loc(x,y);
            this->centroid = loc;
        }

        void setRegularVertices(){
            try {
                if(!this->regular)
                    throw "Not regular polygon";
                else {
                        
                        double angle = 2 * (this->pi)/(this->n_sides);
                        for (int i = 0; i < this->n_sides; i++)
                        {
                            double x = this->centroid._x() + this->radius * cos(i * angle);
                            double y  = this->centroid._y() + this->radius * sin(i * angle);
                            x = round_to(x, 0.0001);
                            y = round_to(y, 0.0001);
                            point loc(x,y);
                            this->vertices.push_back(loc);
                            cout<<endl<<loc;
                        }
                }
            }
            catch(string m) {
                cout<<m;
            }
        }


        void showVertices() {
            for(int i=0; i<this->n_sides; i++)
                cout<<endl<<this->vertices[i];
        }
        

};



int main() {
    polygon p(4, true); //regular triangle or equilateral triangle
    point centre(0,0);
    p.setCentroid(centre);
    p.setRadius(1);

    p.setRegularVertices();

    p.showVertices();
    return 0;
}