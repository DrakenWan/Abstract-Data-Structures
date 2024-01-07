# Matrix linear library
A matrix data structure. I am still building it up. It makes use of a single pointer array on which matrix values are placed in row major form. It has three members: val (which holds the values of matrix), row (number of rows) and col (number of columns).



The matrix operations currently implemented so far:-
* addition  [x]  
* subtraction [x]
* multiplication [x]
* scalar multiplication [x]
* transpose [x]
* inverse [x] (experimental- uses gaussian elimination with partial pivoting)
* stack [x] - to generate augmented matrices (vertical stack and horizontal stack)
* slicing submatrices [x]
* Aggregate functions [ ]
    * max [x]
    * argmax [x]
    * min [x]
    * argmin [x]