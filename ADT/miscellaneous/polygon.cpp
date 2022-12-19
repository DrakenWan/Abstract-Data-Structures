#include<iostream>
#include<vector>
#include "point.h"

using namespace std;

class polygon {
    int n_sides;
    bool regular;
    vector<point> vertices;

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
            cout<<"Polygon with 0 sides initialized.";
        }

        polygon(int n_sides) {
            try {
                if(n_sides < 3)
                    throw n_sides;
                else {
                    this->n_sides = n_sides;
                    this->_initDispMsg_();
                }
            } catch(int n) {
                cout<<"Value Error: number of sides is less than 3. Given input = "<<n;
            }
        }

        //set functions
        void setSides(int n_sides){this->n_sides = n_sides;}
        

};



int main() {
    polygon p(3);
    return 0;
}