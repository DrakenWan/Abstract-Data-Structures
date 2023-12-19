#include<iostream>

using namespace std;

struct Param {
    int x, y;
};


class papa {
    int array[10][10];
    int r, c;
    public:
        void setDims(int row, int col) {
            this->r = row;
            this->c = col;
        }
        void initArr() {
            cout<<"\nEnter "<<this->r*this->c<<" values:-\n";
            for(int i=0; i<this->r; i++)
                for(int j=0; j<this->c; j++)
                    cin>>this->array[i][j];
        }

        void operator()(Param _0, Param _1) {
             cout<<"\n_0 Params received are:- ("<<_0.x<<':'<<_0.y<<")\n";
             cout<<"\n_1 Params received are:- ("<<_1.x<<':'<<_1.y<<")\n";
            }

};

int main() {
    
    int r=5, c=5;
    papa p;
    p.setDims(r,c);
    p.initArr();
    p({1,2}, {0,5});


    // int **arr,*p;
    // int r = 5, c = 5;
    // arr = new int*[r];
    
    // for(int i=0; i<r; i++)
    //  {
    //     p = new int[c];
    //     cout<<"\nEnter "<<c<<" numbers:-\n";
    //     for(int j=0; j<c; j++)
    //         cin>>p[j];

    //     arr[i] = p;
    //  }


    //  for(int i=0; i<r; i++)
    //     {
    //         for(int j=0; j<c; j++)
    //             cout<<arr[i][j]<<" ";
    //         cout<<endl;
    //     }

    
    
    // delete []arr;
    // arr = NULL;
    return 0;
}