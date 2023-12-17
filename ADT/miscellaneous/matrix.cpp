#include<iostream>
#include<omp.h>
#include<stdexcept>

using namespace std;

template<typename DATA>
class matrix {
    /*
        val = flattened 2d array of type DATA in row major form
        row = number of rows of the matrix
        col = number of columns of the matrix

        Note: memory is dynamically allocated for the `val` 
        member variable.  It's lifetime is until 
        the object instance of `matrix` defining it is alive.
    */
    DATA *val;
    int row, col;

    //deallocate memory for Val
    void delMemoryforVal() {
        delete this->val;
        this->val = NULL;
    }

    // memory allocation for internal data structure holding the values
    void getMemoryforVal(int row, int col) {
        this->val = new DATA[row*col];
    }

    public:
        // initialize a square matrix
        matrix(int n) {
            this->row = this->col = n;
            getMemoryforVal(n,n);
        }

        // initialize a rectangular matrix
        matrix(int row, int col) {
            this->row = row;
            this->col = col;
            
            getMemoryforVal(this->row,this->col);
        }

        // initialize a square matrix using a flattened 2d array input
        matrix(DATA *data, int n) {
            this->row =
            this->col = n;

            getMemoryforVal(n,n);

            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    *(val + i*n + j) = *(data + i*n + j);
        }

        // initialize a rectangle matrix using a flattened 2d array input
        matrix(DATA *data, int row, int col) {
            
            this->row = row;
            this->col = col;
            getMemoryforVal(this->row,this->col);
            for(int i=0; i<row; i++)
                for(int j=0; j<col; j++)
                    *(val + i*col + j) = *(data + i*col + j);
        }


        //copy constructor
        matrix(const matrix<DATA> &m) {
            this->row = m.row;
            this->col = m.col;

            this->delMemoryforVal();
            this->getMemoryforVal(this->row, this->col);

            for(int i=0; i<this->row; i++)
                for(int j=0; j<this->col; j++)
                    *(val + (this->col)*i + j) = *(m.val + i*m.col + j);
        }

        // insert/update all the elements in row major form into the internal data structure
        void insertAll();

        // insert value at rth row and cth column
        void insertAt(DATA, int, int);

        // display contents in a 2d grid form
        void display();
        
        ~matrix() {
            delete this->val;
            this->val = nullptr;
            //cout<<"\nCleared heap memory for member `val`.";
        }

        /////// MATRIX OPERATIONS ///////
        matrix<DATA> operator+(matrix const& );
        matrix<DATA> operator-(matrix const& );
        matrix<DATA> operator&(matrix const& ); //matrix multiply
        matrix<DATA> operator*(DATA scalar); //scalar multiplication (scalar on rhs of *)

        //transpose operator
        matrix<DATA> operator!();
        //transpose operation explicit method
        matrix<DATA> transpose();


        //accessibility operations overload
        DATA operator()(int, int);

};


//// identity matrix
template<typename DATA>
matrix<DATA> eye(int n) {
    matrix<DATA> m(n, n);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if(i == j) {
                m.insertAt(1, i, j);
            } else {
                m.insertAt(0, i, j);
            }
        }

    return m;
}

///// MATRIX OPERATIONS DEFINITIONS START HERE ////

template<typename DATA>
matrix<DATA> matrix<DATA>::operator*(DATA scalar) {
    matrix<DATA> m(this->row, this->col);

    for(int i=0; i<this->row; i++)
        for(int j=0; j<this->col; j++) {
            int temp = *(val + (this->col)*i + j);
            *(m.val + i*m.col + j) = scalar * temp;
        }

    return m;
}
            

template<typename DATA>
matrix<DATA> matrix<DATA>::operator&(matrix const &obj) {
        if(this->col != obj.row) {
            throw std::invalid_argument("Internal dimensions do not match.");
            
        }
        else {
            int i, j, k;
            matrix<DATA> m(this->row, obj.col);
            for(i=0; i<m.row; i++)
                for(j=0; j<m.col; j++)
                    *(m.val + i*m.col + j) = (DATA)0; //change this later 
                    //add funct for it as DEFAULT value as addition inverse of
                    // that data


            //else perform multiplication in parallel using openmp
            #pragma omp parallel for private(i,j,k) shared(this->val, obj.val, m)
            for(i=0; i<this->row; i++)
                for(k=0; k<obj.row; k++)
                    for(j=0; j<obj.col; j++)
                        *(m.val + i*m.col + j) += *(val + i*this->col + k) * *(obj.val + k*obj.col + j);

            
            return m;
        }
        
}

template<typename DATA>
DATA matrix<DATA>::operator()(int r, int c)  {
    
    if(r < this->row && c < this->col) {
        return *(val + r*this->col + c);
    } else {
        throw std::invalid_argument("Indices exceed the dimension size.");
    }
}

template<typename DATA>
matrix<DATA> matrix<DATA>::operator!() {
    matrix<DATA> m(this->col, this->row);

    //using insertAt operation to fill in the elements
    for(int i=0; i<m.row; i++)
        for(int j=0; j<m.col; j++)
            *(m.val + i*m.col + j) = *(val + (this->row)*j + i);

    return m;
}

template<typename DATA>
matrix<DATA> matrix<DATA>::transpose() {
    matrix m = !(*this);
    return m;
}

template<typename DATA>
matrix<DATA> matrix<DATA>::operator+(matrix const& obj) {
    if(this->row == obj.row && this->col == obj.col) {
        matrix<DATA> m(obj.row, obj.col);
        // addition and insertion in row major form.
        for(int i=0; i<m.row; i++)
            for(int j=0; j<m.col; j++)
                *(m.val + i*m.col + j) = *(obj.val + i*obj.col + j) + *(val + i*this->col + j);

        return m;
    } else {
        throw std::invalid_argument("dimensions do not match for addition to be valid.");
    }
}


template<typename DATA>
matrix<DATA> matrix<DATA>::operator-(matrix const& obj) {

        if(this->row == obj.row && this->col == obj.col) {
            matrix<DATA> m(obj.row, obj.col);
            // subtraction and insertion in row major form.
            for(int i=0; i<m.row; i++)
                for(int j=0; j<m.col; j++)
                    *(m.val + i*m.col + j) =  *(val + i*this->col + j) - *(obj.val + i*obj.col + j);

            return m;
        } else {
            throw std::invalid_argument("Dimensions do not match for subtraction to be valid.");
        } 
}


template<typename DATA>
void matrix<DATA>::insertAll()  {
    int i,j;
    cout<<"\nNote: you have to insert "<<this->row*this->col<<" values. Values will be filled row-major wise.\n";
    for(i=0; i<this->row; i++)
        for(j=0; j<this->col; j++)
            cin>>*(val + (this->col)*i + j);
}


template<typename DATA>
void matrix<DATA>::insertAt(DATA value, int r, int c)  {
        if( (r>-1 && r < this->row) && (c>-1 && c<this->col)) {
            *(val + (this->col)*r + c) = value;
        } else {
            throw std::invalid_argument("The index values exceed the dimension size of the matrix.");
        }
}

template<typename DATA>
void matrix<DATA>::display()  {
    int i,j;
    cout<<"Matrix:-\n";
    for(i=0; i<this->row; i++) {
        for(j=0; j<this->col; j++)
            cout<<*(val + (this->col)*i + j )<<" ";
        cout<<"\n";
    }
}



/////// MAIN FUNCTION AND UTILS/////////

void init2dArray(int *array, int size_0, int size_1) {
    /*
        UTIL FUNCTION
        Flattened 2d array in row major form will be initialised using this
    */
   cout<<"\nPlease insert "<<size_0*size_1<<" values in row major form for a "<<size_0<<'x'<<size_1<<" matrix:-\n";
    for(int i=0; i<size_0; i++)
        for(int j=0; j<size_1; j++)
            cin>>*(array + i*size_1 + j);
}

int main() {

    int row=2, 
        col=3,
        row2=3,
        col2=2;

    int *array1 = new int[row*col];
    int *array2 = new int[row2*col2];
    init2dArray(array1, row, col); // 2x3 array
    init2dArray(array2, row2, col2); // 3x2 array

    matrix<int> m1(array1, row, col); //2x3 matrix
    matrix<int> m2(array2, row2, col2); //3x2 matrix
    
    matrix<int> m3 = m1 & m2;

    m1.display();
    m2.display();

    cout<<"\nMatrix Multiplication Result:-\n";
    m3.display();

    matrix<int> m4 = m3*2;
    m4.display();

    delete array1;
    delete array2;
    array1 = NULL;
    array2 = NULL;

    return 1;
}


/////// MAIN FUNCTION AND UTILS END HERE /////////
