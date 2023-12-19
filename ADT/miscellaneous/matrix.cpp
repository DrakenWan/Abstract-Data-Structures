#include<iostream>
#include<omp.h>
#include<stdexcept>


//extra imports for utility
#include<random>

using namespace std;


template<typename DATA>
class matrix {
    /*  
        matrix abstract DS reflects properties and behaviour of a matrix

        DATA MEMEBERS:-
            val = flattened 2d array of type DATA in row major form
            row = number of rows of the matrix
            col = number of columns of the matrix

        Note: 
            1.  memory is dynamically allocated for the `val` 
                member variable.  It's lifetime is until 
                the object instance of `matrix` defining it is alive.
            2.  This class object makes use of openMP paralleisation to 
                take advantage of parallel computing in some operations
                such as matrix multiplication.
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

    
    // validate the Param values
    bool validateParams(int x, int y, int dim) {
        bool validatex = (x > -1 && x < dim+1);
        bool validatey = (y > -1 && y < dim+1);
        bool validatexlty = (x < y);
        if( validatex && validatey && validatexlty)
            return true;
        else
            return false;
    }
    
    //////////////////////////

    public:
        //getdimensions
        int getDim(int axis=0) {
            if(axis=0) return this->row;
            if(axis=1) return this->col;
            else
                throw std::invalid_argument("Wrong axis. Accepted set of values {0,1}");
        }
        int rows() {return this->row;}
        int cols() {return this->col;}

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
        matrix<DATA> T(){ return this->transpose();};

        //accessibility operations overload
        DATA operator()(int, int); //access an element of the matrix
        //void operator()(Params, Params);

        // sliceu!
        matrix<DATA> slice(int, int, int, int);

        // raise each element to an integer power
        matrix<DATA> operator^(int);
        ////////////////  OPERATIONS END /////////////////
        
        
        /// Generate Augmented matrix (vertical stack or horizontal stack) ///
        matrix<DATA> hStack(matrix const& ); // horizontal stack - hStack
        matrix<DATA> vStack(matrix const& ); // vertical  stack - vStack
        matrix<DATA> stack(matrix const& obj, bool vert=false); //generalized stack - stack
        //////////////////////////////////////////////////////////////////////


};


//// STACKING OPERATIONS ////
template<typename DATA>
matrix<DATA> matrix<DATA>::stack(matrix const& obj, bool vert) {
    if(vert)
        return this->vStack(obj);
    else
        return this->hStack(obj);
}

template<typename DATA>
matrix<DATA> matrix<DATA>::hStack(matrix const& obj) {
    if(this->row != obj.row)
        throw std::invalid_argument("The row dimensions do not match.");
    
    // initialize the augmented matrix
    matrix<DATA> m(this->row, this->col + obj.col);

    for(int i=0; i<m.row; i++) {
        for(int j=0; j<this->col; j++)
            *(m.val + i*m.col + j) = *(val + (this->col)*i + j);

        for(int j=0; j<obj.col; j++)
            *(m.val + i*m.col + (j+this->col)) = *(obj.val + i*obj.col + j);
    }

    return m;
}

template<typename DATA>
matrix<DATA> matrix<DATA>::vStack(matrix const& obj) {
    if(this->col != obj.col)
        throw std::invalid_argument("The column dimensions do not match.");

    // initialize our augmented matrix
    matrix<DATA> m(this->row + obj.row, this->col);

    
    for(int j=0; j<m.col; j++) {
        for(int i=0; i<this->row; i++)
            *(m.val + i*m.col + j) = *(val + i*m.col + j);

        for(int i=0; i<obj.row; i++)
            *(m.val + (i+this->row)*m.col + j) = *(obj.val + i*obj.col + j);
    }

    return m;
    
}
//// STACKING OPERATIONS END ////



///// MATRIX OPERATIONS DEFINITIONS START HERE ////

template<typename DATA>
matrix<DATA> matrix<DATA>::operator^(int pow) {
    /*
        This is not a numerically sound operation.
        Use at your own risk.
        This is only used for positive integer powers.
        Will probably just use math.pow function which is
        numerically stable. 

        NOTE:
            Just want to see how this restricted logic works for me.
            In case of integer matrices, this is not an issue but when
            it would come to dealing with floats using this operation
            it might lead to cases where the data is lost.
    */
    matrix<int> m(this->row, this->col);

    for(int i=0; i<(m.row*m.col); i++) {
        int prod=1;

        //exponent logic using loop
        for(int j=0; j<pow; j++)
            prod *= *(val + i);
        
        *(m.val + i) = prod;
    }

    return m;
}

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


// slicing operations
template<typename DATA>
matrix<DATA> matrix<DATA>::slice(int x_0, int y_0, int x_1, int y_1) {
    /*
        Takes in 4 integer parameters:-
            x_0 : start index of row dimension
            y_0 : end index of row dimension (exclusive)
            x_1 : start index of col dimension
            y_1 : end index of col dimension (exclusive)

        RETURNS 
           a (y_0 - x_0) x (y_1 - x_1) submatrix from the given input matrix
        
        USAGE
            Suppose you have a 5x4  matrix of some random integervalues
            You invoke `matrix<int> subMatrix = A.slice(1,4, 1,2)`. This will
            return a 2x1 submatrix of the original matrix.

              5x4 Matrix                        2x1 sub matrix
            [[1, 2, 3, 4],                          
             [1, 4, 3, 2],                           [[4],
             [3, 1, 2, 4],         =====>             [1]]
             [2, 3, 4, 1],
             [4, 2, 1, 3]]
    */
    bool validation = (this->validateParams(x_0, y_0, this->row)) && (this->validateParams(x_1, y_1, this->col));
    //cout<<"Params _0"<<x_0<<','<<y_0;
    //cout<<"\nParams _1"<<x_1<<','<<y_1;

    if (validation) {
        matrix<DATA> m(y_0 - x_0, y_1 - x_1);

        for(int i=0; i<m.row; i++) {
            for(int j=0; j<m.col; j++) {
                *(m.val + i*m.col + j) = *(val + (i + x_0)*(this->col) + (j + x_1));
            }
        }

        return m;

    } else {
        throw std::invalid_argument("Bad indices reported. Check your index Params.");
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
    cout<<"\nNote: you have to insert "<<this->row*this->col<<" values. Values will be filled row-major wise in a "<<this->row<<'x'<<this->col<<" matrix.\n";
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

void init2dRandArray(int *array, int size_0, int size_1) {
    /*
     UTIL FUNCTION
        Flattened 2d array in row major form will be initialised using a
        uniform integer distribution.
    */

   cout<<"\nInitializing our random 2d integer array";
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(0, 9);

   for(int i=0; i<size_0; i++)
    for(int j=0; j<size_1; j++)
        *(array + i*size_1 + j) = distribution(generator);
}

int main() {

    // int row=2, 
    //     col=3,
    //     row2=3,
    //     col2=2;

    // int *array1 = new int[row*col];
    // int *array2 = new int[row2*col2];
    // init2dArray(array1, row, col); // 2x3 array
    // init2dArray(array2, row2, col2); // 3x2 array

    // matrix<int> m1(array1, row, col); //2x3 matrix
    // matrix<int> m2(array2, row2, col2); //3x2 matrix
    
    // matrix<int> m3 = m1 & m2;

    // m1.display();
    // m2.display();

    // cout<<"\nMatrix Multiplication Result:-\n";
    // m3.display();

    // matrix<int> m4 = m3*2;
    // m4.display();

    // delete array1;
    // delete array2;
    // array1 = NULL;
    // array2 = NULL;


    int r = 5, c = 4;
    int *arr1 = new int[r*c], *arr2= new int[r*c];
    init2dRandArray(arr1, r, c);
    init2dRandArray(arr2, c, r);

    matrix<int> m10(arr1, r, c);
    matrix<int> m11(arr2, c, r);
    matrix<int> m12 = m10 & m11;

    m10.display();
    m11.display();
    cout<<"\nMatrix Mul Result:-\n";
    m12.display();

    matrix<int> m11T = m11.T();
    m11T.display();
    delete arr1;
    delete arr2;
    arr1 = NULL;
    arr2 = NULL;


    //augmentation 
    cout<<"\nGenerating Horinzontal stack matrix:-\n";
    matrix<int> eye5 = eye<int>(r);

    cout<<"matrix m10 | ";
    m10.display();
    cout<<"Identity matrix 5x5 | ";
    eye5.display();

    matrix<int> augmentedMatrix = m10.hStack(eye5);

    cout<<"\nAugmented matrix | ";
    augmentedMatrix.display();


    cout<<"\nGenerating Horinzontal stack matrix:-\n";
    matrix<int> eye4 = eye<int>(c);

    cout<<"matrix m10 | ";
    m10.display();

    cout<<"Identity matrix 4x4 | ";
    eye4.display();

    matrix<int> augmentedMatrix2 = m10.vStack(eye4);
    cout<<"\nAugmented matrix | ";
    augmentedMatrix2.display();

    // exponend
    cout<<"\n\nRaise each element to an integer power:-\n";
    
    int *arrA = new int[2*2];
    init2dArray(arrA, 2, 2);
    matrix<int> A(arrA, 2, 2);
    delete arrA;
    arrA = NULL;

    cout<<"matrix A | ";
    A.display();

    matrix<int> A3 = A^3;
    cout<<"\nResultant cube valued matrix | ";
    A3.display();
    

    cout<<"\n1X1 Matrix example:-\n";
    int val = 10;
    int *arr = &val;
    matrix<int> B(arr,1,1);
    B.display();
    
    cout<<endl;
    cout<<B(0,0)<<endl;

    // Matrix indexing example
     cout<<"\nMatrix slicing example:- (Slicing [(1:2),(0:1)]\n";
     cout<<"Original matrix m10 | ";
     m10.display();

    matrix<int> subMat10 = m10.slice(0,5,0,2);
    cout<<subMat10.getDim(0)<<'x'<<subMat10.getDim(1)<<" Submatrix | ";
    subMat10.display();
    return 0;
}


/////// MAIN FUNCTION AND UTILS END HERE /////////
