#include<iostream>
#include<omp.h>
#include<stdexcept>


//extra imports for utility
#include<random>

// macros for deallocation
#define deAlloc(x) delete[] x; x = nullptr;


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

        Guideline:
            1: While using a matrix operation ensure you close the operands with 
               parenthesis with the binary or unary operator that is being used
                For example, to perform multiplication of A and B to give C we will
                             write "matrix<int> C = (A & B);"
    */
    DATA *val;
    int row, col;

    //deallocate memory for Val
    void delMemoryforVal() {
        delete[] this->val;
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
        matrix<DATA> getDims() {
            /*
                Returns a 1x2 integer matrix (say Dims) with row in Dims(0,0) and col in Dims(0,1) 
            */

           matrix<int> Dims(1,2);
           Dims(0,0) = this->row;
           Dims(0,1) = this->col;
           
           return Dims;
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
            delete[] val;
            val = NULL;
            //std::cout<<"\nCleared heap memory for member `val`.";
        }

        /////// MATRIX OPERATIONS ///////
        matrix<DATA> operator+(matrix const& );
        matrix<DATA> operator-(matrix const& );
        matrix<DATA> operator&(matrix const& ); //matrix multiply
        matrix<DATA> operator*(DATA scalar); //scalar multiplication (scalar on rhs of *)
        bool operator==(matrix const &); // matrix equal operation

        //transpose operator
        matrix<DATA> operator!(); 
        //transpose operation explicit method
        matrix<DATA> transpose();
        matrix<DATA> T(){ return this->transpose();};

        //accessibility operations overload
        DATA& operator()(int, int); //access an element of the matrix
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


        /// aggregate functions ///
        // max
        matrix<DATA> max(int dim=-1);

        //argmax
        matrix<DATA> argmax(int dim=-1);
        
        // min
        matrix<DATA> min(int dim=-1);

        //argmin
        matrix<DATA> argmin(int dim=-1);
        //// aggregate functions end ////




        /// QUERY methods
        bool isSquare() { if(this->col == this->row) return true; else return false;}
        bool isSymmetric();
        DATA item();
};


/////// AGGREGATE FUNCTIONS ///////

///// Min
template<typename DATA>
matrix<DATA> matrix<DATA>::min(int dim) {
     DATA minElem;
    if(dim == -1) {
            /* Returns a 1x1 matrix of max value */
            matrix<DATA> m0(1,1);

            // might subroutine the below repetitive code
            minElem = *val;
            for(int i=1; i<this->row*this->col; i++)
                if( minElem > *(val + i)) {
                    minElem = *(val + i);
                }

            m0.insertAt(minElem, 0, 0);
            return m0;
    } //dim == -1
     else {
    
        if(dim == 0) {

                /* Returns a 1xcol matrix of max value in each jth column
                this operation is performed along the 0th axis (row axis)
                */

                matrix<DATA> m1(1, this->col);

                for(int j=0; j<this->col; j++) {
                    minElem = *(val +  j);

                    for(int i=1; i<this->row; i++)
                        if( minElem > *(val + i*(this->col) + j) )
                            minElem = *(val + i*(this->col) + j);

                    m1.insertAt(minElem, 0,j);
                }
                return m1;
        } // dim == 0

        else {
            if(dim == 1) {
                /*
                    Returns a rowx1 matrix of max value in each ith row
                    this operation is performed along the 1th axis (col axis)
                */

               matrix<DATA> m2(this->row, 1);
               for(int i=0; i<this->row; i++) {
                    minElem = *(val + i*(this->col));

                    for(int j=1; j<this->col; j++) {
                        if( minElem > *(val + i*(this->col) + j) )
                            minElem = *(val + i*(this->col) +j);
                    }

                    m2.insertAt(minElem, i, 0);
               }
              return m2;
            } else {
                throw std::invalid_argument("Invalid dim index used.");
            }
        } 
    }
}

//// Indices of Min element
template<typename DATA>
matrix<DATA> matrix<DATA>::argmin(int dim) {
int minIdx_i, minIdx_j;
    if(dim == -1) {
        /*
            Calculate the index of max element in entire matrix
            Returns a 1x2 matrix with ith index at (0,0) and jth index at (0,1)
        */
            matrix<DATA> m0(1,2);

            // might subroutine the below repetitive code
            minIdx_i = 0;
            minIdx_j = 0;
            DATA minElem = *(val + minIdx_i*(this->col) + minIdx_j);
            for(int i=0; i<this->row; i++) 
                for(int j=0; j<this->col; j++)
                    {
                        if(minElem > *(val + i*(this->col) + j))
                            {
                                minElem = *(val + i*(this->col) + j);
                                minIdx_i = i;
                                minIdx_j = j;
                            }
                    }

            // insert the indices at (0,0) and (0,1)
            m0.insertAt(minIdx_i, 0, 0);
            m0.insertAt(minIdx_j, 0, 1);
            return m0;
    } else {
        if(dim == 0) {

                /* Returns a 1xcol matrix of index of max value in each jth column
                this operation is performed along the 0th axis (row axis)
                */

                matrix<DATA> m1(1, this->col);

                for(int j=0; j<this->col; j++) {
                    int minIdx_i = 0;
                    DATA minElem = *(val + minIdx_i*(this->col) + j);
                    for(int i=1; i<this->row; i++)
                        if( minElem > *(val + i*(this->col) + j) ) {
                            minElem = *(val + i*(this->col) + j);
                            minIdx_i = i;
                        }

                    m1.insertAt(minIdx_i, 0,j);
                }
                return m1;
        } // dim == 0 condn end
         else {
            if(dim == 1) {
                /*
                    Returns a rowx1 matrix with index of max value in each ith row
                    this operation is performed along the 1th axis (col axis)
                */

               matrix<DATA> m2(this->row, 1);
               for(int i=0; i<this->row; i++) {
                    int minIdx_j = 0;
                    DATA minElem = *(val + i*(this->col) + minIdx_j);
                    
                    for(int j=1; j<this->col; j++) {
                        if( minElem > *(val + i*(this->col) + j) ) {
                            minElem = *(val + i*(this->col) + j);
                            minIdx_j = j;
                        } 
                    }

                    m2.insertAt(minIdx_j, i, 0);
               }
              return m2;
            } //dim == 1 condn end
            else {
                throw std::invalid_argument("The axis value is not correct.");
            }
        }
    }
}


//// Max
template<typename DATA>
matrix<DATA> matrix<DATA>::max(int dim) {
    DATA maxElem;
    if(dim == -1) {
            /* Returns a 1x1 matrix of max value */
            matrix<DATA> m0(1,1);

            // might subroutine the below repetitive code
            maxElem = *val;
            for(int i=1; i<this->row*this->col; i++)
                if( maxElem < *(val + i)) {
                    maxElem = *(val + i);
                }

            m0.insertAt(maxElem, 0, 0);
            return m0;
    } //dim == -1
     else {
    
        if(dim == 0) {

                /* Returns a 1xcol matrix of max value in each jth column
                this operation is performed along the 0th axis (row axis)
                */

                matrix<DATA> m1(1, this->col);

                for(int j=0; j<this->col; j++) {
                    maxElem = *(val +  j);

                    for(int i=1; i<this->row; i++)
                        if( maxElem < *(val + i*(this->col) + j) )
                            maxElem = *(val + i*(this->col) + j);

                    m1.insertAt(maxElem, 0,j);
                }
                return m1;
        } // dim == 0

        else {
            if(dim == 1) {
                /*
                    Returns a rowx1 matrix of max value in each ith row
                    this operation is performed along the 1th axis (col axis)
                */

               matrix<DATA> m2(this->row, 1);
               for(int i=0; i<this->row; i++) {
                    maxElem = *(val + i*(this->col));

                    for(int j=1; j<this->col; j++) {
                        if( maxElem < *(val + i*(this->col) + j) )
                            maxElem = *(val + i*(this->col) +j);
                    }

                    m2.insertAt(maxElem, i, 0);
               }
              return m2;
            } else {
                throw std::invalid_argument("Invalid dim index used.");
            }
        } 
    }
    
}

/// Indices of max
template<typename DATA>
matrix<DATA> matrix<DATA>::argmax(int dim) {
    int maxIdx_i, maxIdx_j;
    if(dim == -1) {
        /*
            Calculate the index of max element in entire matrix
            Returns a 1x2 matrix with ith index at (0,0) and jth index at (0,1)
        */
            matrix<DATA> m0(1,2);

            // might subroutine the below repetitive code
            maxIdx_i = 0;
            maxIdx_j = 0;
            DATA maxElem = *(val + maxIdx_i*(this->col) + maxIdx_j);
            for(int i=0; i<this->row; i++) 
                for(int j=0; j<this->col; j++)
                    {
                        if(maxElem < *(val + i*(this->col) + j))
                            {
                                maxElem = *(val + i*(this->col) + j);
                                maxIdx_i = i;
                                maxIdx_j = j;
                            }
                    }

            // insert the indices at (0,0) and (0,1)
            m0.insertAt(maxIdx_i, 0, 0);
            m0.insertAt(maxIdx_j, 0, 1);
            return m0;
    } else {
        if(dim == 0) {

                /* Returns a 1xcol matrix of index of max value in each jth column
                this operation is performed along the 0th axis (row axis)
                */

                matrix<DATA> m1(1, this->col);

                for(int j=0; j<this->col; j++) {
                    int maxIdx_i = 0;
                    DATA maxElem = *(val + maxIdx_i*(this->col) + j);
                    for(int i=1; i<this->row; i++)
                        if( maxElem < *(val + i*(this->col) + j) ) {
                            maxElem = *(val + i*(this->col) + j);
                            maxIdx_i = i;
                        }

                    m1.insertAt(maxIdx_i, 0,j);
                }
                return m1;
        } // dim == 0 condn end
         else {
            if(dim == 1) {
                /*
                    Returns a rowx1 matrix with index of max value in each ith row
                    this operation is performed along the 1th axis (col axis)
                */

               matrix<DATA> m2(this->row, 1);
               for(int i=0; i<this->row; i++) {
                    int maxIdx_j = 0;
                    DATA maxElem = *(val + i*(this->col) + maxIdx_j);
                    
                    for(int j=1; j<this->col; j++) {
                        if( maxElem < *(val + i*(this->col) + j) ) {
                            maxElem = *(val + i*(this->col) + j);
                            maxIdx_j = j;
                        } 
                    }

                    m2.insertAt(maxIdx_j, i, 0);
               }
              return m2;
            } //dim == 1 condn end
            else {
                throw std::invalid_argument("The axis value is not correct.");
            }
        }
    }
}



/////// AGGREGATE FUNCTIONS END ////////////

//// QUERY METHOD DEFINITIONS ////

template<typename DATA>
bool matrix<DATA>::isSymmetric() {
    if(this->row == this->col)
     {
        matrix<DATA> Transpose = this->T();
        if(Transpose == *this)
            return true;
     }

     return false;
}


template<typename DATA>
DATA matrix<DATA>::item() {
    if(this->row == 1  && this->col == 1) {
        return *val; 
    } else {
        throw std::invalid_argument("To throw an item out it is supposed to be 1x1 matrix.");
    }
}
/////////////////////////////////


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
bool matrix<DATA>::operator==(matrix const& m) {
    
    if(row == m.row && col == m.col) {
        bool equal = true;
        for(int i=0; i<row*col; i++)
            {
                if(*(val + i) != *(m.val + i))
                    {
                        equal = false;
                        break;
                    }
            }
        return equal;
    } else {
        return false;
    }
}


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
DATA& matrix<DATA>::operator()(int r, int c)  {
    
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
            return a 3x1 submatrix of the original matrix.

              5x4 Matrix                        3x1 sub matrix
            [[1, 2, 3, 4],                          
             [1, 4, 3, 2],                           [[4],
             [3, 1, 2, 4],         =====>             [1],
             [2, 3, 4, 1],                            [3]] 
             [4, 2, 1, 3]]
    */
    bool validation = (this->validateParams(x_0, y_0, this->row)) && (this->validateParams(x_1, y_1, this->col));
    //std::cout<<"Params _0"<<x_0<<','<<y_0;
    //std::cout<<"\nParams _1"<<x_1<<','<<y_1;

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


// TRANSPOSE OPERATION
template<typename DATA>
matrix<DATA> matrix<DATA>::operator!() {
    matrix<DATA> m(this->col, this->row);

    //using insertAt operation to fill in the elements
    for(int i=0; i<m.row; i++)
        for(int j=0; j<m.col; j++)
            m.insertAt(*(val + (this->col)*j + i),i,j);
            //*(m.val + i*m.col + j) = *(val + (m.row)*i + j);

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
    std::cout<<"\nNote: you have to insert "<<this->row*this->col<<" values. Values will be filled row-major wise in a "<<this->row<<'x'<<this->col<<" matrix.\n";
    for(i=0; i<this->row; i++)
        for(j=0; j<this->col; j++)
            std::cin>>*(val + (this->col)*i + j);
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
    std::cout<<"\nMatrix:-\n";
    for(i=0; i<this->row; i++) {
        for(j=0; j<this->col; j++)
            std::cout<<*(val + (this->col)*i + j )<<" ";
        std::cout<<"\n";
    }
}



/////// MAIN FUNCTION AND UTILS/////////

template<typename DATA>
matrix<DATA> diagonal(int n, DATA value) {
    matrix<DATA> m(n);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            {
                if(i==j)
                    m.insertAt(value, i, j);
                else
                    m.insertAt(0, i, j);
            }
    
    return m;
}


//// identity matrix
template<typename DATA>
matrix<DATA> eye(int n) {
    matrix<DATA> m(n);
    
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
   std::cout<<"\nPlease insert "<<size_0*size_1<<" values in row major form for a "<<size_0<<'x'<<size_1<<" matrix:-\n";
    for(int i=0; i<size_0; i++)
        for(int j=0; j<size_1; j++)
            std::cin>>*(array + i*size_1 + j);
}

void init2dRandArray(int *array, int size_0, int size_1) {
    /*
     UTIL FUNCTION
        Flattened 2d array in row major form will be initialised using a
        uniform integer distribution.
    */

   std::cout<<"\nInitializing our random 2d integer array";
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(0, 9);

   for(int i=0; i<size_0; i++)
    for(int j=0; j<size_1; j++)
        *(array + i*size_1 + j) = distribution(generator);
}


int main() {
    int *array;
    int N = 4;
    array = new int[N*N];
    init2dRandArray(array, N, N);

    // create our D matrix
    matrix<int> D(array, N);
    deAlloc(array);

    D.display();
    
    std::cout<<"\n\nFinding max and its indices:-";
    std::cout<<"\nMax element in entire matrix: | ";
    matrix<int> maxD = D.max();
    maxD.display();
    std::cout<<" at index ";
    matrix<int> maxDIdx = D.argmax();
    maxDIdx.display();

    std::cout<<"\n\nMax in each column (or along rows / 0th axis):- ";
    matrix<int> maxD0axis = D.max(0);
    maxD0axis.display();
    matrix<int> maxD0axisIdx = D.argmax(0);
    std::cout<<" at index ";
    maxD0axisIdx.display();

    std::cout<<"\n\nMax in each row (or along columns / 1th axis):- ";
    matrix<int> maxD1axis = D.max(1);
    maxD1axis.display();
    matrix<int> maxD1axisIdx = D.argmax(1);
    std::cout<<" at index ";
    maxD1axisIdx.display();


    std::cout<<"\nMin element in entire matrix: | ";
    matrix<int> minD = D.min();
    minD.display();
    std::cout<<" at index ";
    matrix<int> minDIdx = D.argmin();
    minDIdx.display();


    std::cout<<"\n\nMin in each column ( or along rows / 0th axis):- ";
    matrix<int> minD0axis = D.min(0);
    minD0axis.display();
    matrix<int> minD0axisIdx = D.argmin(0);
    std::cout<<" at index ";
    minD0axisIdx.display();


    std::cout<<"\n\nMin in each row (or along columns / 1th axis):- ";
    matrix<int> minD1axis = D.min(1);
    minD1axis.display();
    matrix<int> minD1axisIdx = D.argmin(1);
    std::cout<<" at index ";
    minD1axisIdx.display();

    return 0;
}


/////// MAIN FUNCTION AND UTILS END HERE /////////
