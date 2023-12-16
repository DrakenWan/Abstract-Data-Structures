## Miscellaneous Data Structures
Any sort of miscellaneous data structure that doesn't fit into the broadly/generally taught DS are put here. These can be something that are conceptual or very restrictive or specialised in their working. Below is the list of some of the data structures created so far. I will keep adding more and keep refining the existing ones.


## Data Structures

### Point

Point data structure is a concept of a point in a 2d or 3d space. This DS only accomodates for 2d or 3d points. This can be used in different areas such as concept of location can be realised using this data structure.


### Agent

Agent DS is just something I wanted to conceive for a long time I am thinking of creating an agent that can traverse a 2d map. An agent has a name, weight and location. Location makes use of Point data structure.


### Polygon

This is still in progress. Basically trying to achieve a data structure that succinctly captures the essence of a polygon. I am trying my best. xD. I have done some progress on it but I need to verify some results.


### Complex

This is the complex class that I have created. It tries to realise the concept of complex numbers using this data structure. I have added methods that accomodate for certain arithmetic operations that are eligible for complex numbers. Also added some operator overloads to access the components of the data structure or compare the values.


### String

This is also still in works. String data structure is basically trying to achieve what every other string class out there does. The internal data structure that holds the data is made of std::vector. I will give utmost care to each and every method I conceive and see if there is an efficient way to perform certain operation.


### Location
Name is self-explanatory. It has attributes:-
* `id`: unique identifier
* `loc`: a `point` class instance
* `type`: a std::string type representing the terrain/type of location, for instace, `open path` or `wall`.


### MATRIX
A matrix data structure. I am still building it up. It makes use of a single pointer array on which matrix values are placed in row major form. It has three members: val (which holds the values of matrix), row (number of rows) and col (number of columns).

The matrix operations currently implemented so far:-
* addition  [x]
* subtraction [ ]
* multiplication [ ]
* transpose [x]