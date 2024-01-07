# Miscellaneous Data Structures
Any sort of data structure that doesn't fit into the broadly classified data structures are put here. These can be something that are specialised in their use or behaviour. Below is the list of some of the data structures created so far. I will keep adding more and keep refining the existing ones. Below are explanations or guidelines explaining the data structures in this directory.


## Point

Point data structure is a concept of a point in a 2d or 3d space. It only accomodates for 2d or 3d points. This can be used in different areas such as concept of location can be realised using this data structure. Don't forget to include the header file `point.h` in your source file.

### Initialize a point
There are several ways to define a point. By default calling a point initializes a point in 3D space.

```cpp

// Define a 3d point in space at origin (0,0,0)
point p;

// Define a 2d point at (1,0.5)
double x=1.0, y=0.5;
point p2(x, y);

// Define a 3d point at (3,1,2)
double x=3.0, y=1.0, z=2.0;
point p3(x,y,z);

// initialize a point `p4` with values of `p3`
point p4 = p3;
```

### Operations with points
There are several operations that you can perform. A lot of these will be explained using examples.

#### Addition
Adding two points will just add elements of corresponding dimensions of the points.

Adding a 2d point with 3d point will result in a 3d point


```cpp
// adding two points
point p1(1, 2.5, 0.5);
point p2(-1, 0, 1);
point p3 = p1 + p2;
std::cout << p3; // outputs - (0, 3.5, 1.5)

// adding a 2d pt with 3d pt
point p4(1,2);
point p5(1, 0.5, -1.5);
point p6 = p4 + p5; // outputs - (2,2.5,-1.5)
std::cout << p6;
std::cout << p6._2D(); // outputs - 1
// _2D() method checks whether a point is 2d or not

// adding a scalar to all elements of a point
double scalar = 0.5;
point p7 (1, 0.5, -0.5);
point p8 = p7 + scalar;
std::cout << p8; // outputs - (1.5, 1, 0)
```

#### Subtraction
Subtraction follows the same pattern as addition.

Note: there is no operation defined for subtracting a scalar from a point yet.

#### Scalar multiplication

```cpp
point p1(-2,4,2);
double scalar = 0.5;
point p2 = p1*scalar;
std::cout << p2; // outputs = (-1,2,1)
```

#### Dot product
```cpp
point p1(-1,0,2);
point p2(2,0,1);
double p1dotp2 = p1&p2;
std::cout << p1dotp2; // outputs - 0
```

### Relational operations
These compares distances of both points from origin while comparing. The logic will be changed asap.

```cpp
point p1(1,0,0);
point p2(2,0,0);
point p3, p4;

point p5(-1,0,0);
point p6(1,0,0);

std::cout << (p1 < p2>); // outputs - 1
std::cout << (p3 == p4); // outputs - 1
std::cout << (p5 == p6); // outputs - 1
```

### Indexing
You can access the internal elements of a point using [] indexing operator

```cpp
point p1(1.5, -1, 3.2);

std::cout<<"\nAccess element from x-axis:-\n";
std::cout<<p1['x']<<std::endl;
std::cout<<p1[0]<<std::endl<<std::endl;

std::cout<<"\nAccess element from y-axis:-\n";
std::cout<<p1['y']<<std::endl;
std::cout<<p1[1]<<std::endl<<std::endl;

std::cout<<"\nAccess element from z-axis:-\n";
std::cout<<p1['z']<<std::endl;
std::cout<<p1[2]<<std::endl<<std::endl;

point p2(1.5, 2);
std::cout<<"\nTrying to access z-axis element on a 2d point:-\n";
std::cout<<p2[2]; // will throw an exception
```

You can even change the internal element using indexing operator []
```cpp
point p3(0.5, 0.5, 2);

std::cout<<p1<<std::endl;

//changing z axis value to 0.5
p3[2] = 0.5;
std::cout<<p1;
```

### distance

Distance method calculates the distance between two given points.

```cpp
point p1(1, 0, 2);
point p2(-2, 0, 1);
std::cout << p1.distance(p2); // outputs - 3.16228
```


## Agent

Agent DS is just something I wanted to conceive for a long time I am thinking of creating an agent that can traverse a 2d map. An agent has a name, weight and location. Location makes use of Point data structure.


## Polygon

This is still in progress. Basically trying to achieve a data structure that succinctly captures the essence of a polygon. I am trying my best. xD. I have done some progress on it but I need to verify some results.


## Complex

This is the complex class that I have created. It tries to realise the concept of complex numbers using this data structure. I have added methods that accomodate for certain arithmetic operations that are eligible for complex numbers. Also added some operator overloads to access the components of the data structure or compare the values.


## String

This is also still in works. String data structure is basically trying to achieve what every other string class out there does. The internal data structure that holds the data is made of `std::vector`. I will give utmost care to each and every method I conceive and see if there is an efficient way to perform certain operation.

There are two data members in the string class- `feed` and `_size`. `_size` keeps track of the length of the string and `feed` is the internal standard vector data structure that holds the values of string.

Unlike python string, this string is mutable. We can change the internal elements of a string.

### Initializing string
The default initialisation is an empty string with size `0`.
```cpp
// empty string
String empty;
std::cout<<empty; // prints nothing

// initializing a string with size 10
String size10String(10);
std::cout<<size10String; // prints nothing

//initializing string with a vector<char> as input
vector<char> data = {'K', 'a', 'r', 't', 'i', 'k', 'a', 'y'};
String name(data);
std::cout<<name; // outputs - Kartikay

//initialize with a const char* literal
String name = "Kartikay";
std::cout<<name;

// initialize a string with value from an old string
String name = "Kartikay";
String candidate = name;
std::cout<<candidate; // outputs - Kartikay
```

### String operations

There are some operations that can be performed on string using the overloaded binary operator methods for +, *, etc

#### Concatenate
`+` is the concatenate operation.

```cpp
String greet = "Hello ";
String name = "Kartikay";
String end = "!!";
String greeting = greet + name + end;
std::cout<<greeting; //Outputs - Hello Kartikay!!
```

You can also concatenate a character to the string using `+`

```cpp
String end2 = '!';
String greeting2 = (greet + name) + end2;
std::cout << greeting; // Outputs - Hello Kartikay!
```

Concatenation can also using `append` method.

#### Manipulate internal elements

These operations are some generic implementations that make modifications to the internal elements and return a newly created String after the modification to the internal elements.
Some of the operations are descriptive by their names and have very standard names such as `capitalize`, `upper`, `lower`, `split`, `strip`, etc.


```cpp
// Capitalize the first letter in the string
String sentence = "hello i am New To this Field.";
std::cout<<sentence.capitalize();

// convert lowercase letters to uppercase
std::cout<<sentence.upper();

// convert uppercase letters
std::cout<<sentence.lower();

std::cout<<sentence.startsWith('h'); // outputs - 1
std::cout<<sentence.endsWith('.'); //outputs - 1


```


## Location
Name is self-explanatory. It has attributes:-
* `id`: unique identifier
* `loc`: a `point` class instance
* `type`: a std::string type representing the terrain/type of location, for instace, `open path` or `wall`.


## MATRIX

Matrix linear library. Still in works. 
(./matrix/Readme.md)[Readme for guidance]