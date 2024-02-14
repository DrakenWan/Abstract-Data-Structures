# Matrix linear library (ARCHIVED) GO TO [Matrix](https://github.com/DrakenWan/Matrix)
A matrix data structure. I am still building it up. It makes use of a single pointer array on which matrix values are placed in row major form. It has three members: val (which holds the values of matrix), row (number of rows) and col (number of columns).

I will keep updating this part as well but I have borrowed this matrix data structure for my linear algebra repo - [Matrix](https://github.com/DrakenWan/Matrix).

It is recommended that you go to the Matrix library linked above. It has more updated version of this data structure. This part of the AbstractDS library is archived.


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