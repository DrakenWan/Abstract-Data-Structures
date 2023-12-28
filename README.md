# Abstract Data Structures

I am trying to create a repository with Data structures and algorithms from scratch. I am actively working over this library right now. Feel free to help in anyway possible. I am revisiting my Algorithms lessons and doing this helps me revise better. This also helps me practice and stay connected to C++.

The entire library is to be written in C++ but if I feel the need I might adjust the repo to include code in Python as well as C languages.

I do not have any plan in regards to it's structure or where to start off. I am currently sticking to learning from CLRS and Coursera and whatever DS or A comes my way I will implement it into the repo after learning of it.

## Data Structures
There are several standard data structures and many other specific purpose data structures. Whatever may be the category, all of them are present within the `ADT` subfolder.
In the ADT subfolder, there are three main abstract data structures of `stack`, `queue` and `priority queue`. Then there are different implementations of `tree` data structures that will go into `trees` folder. There is a folder present for `graph` data structures. Some of these folders have their own `Readme``files that you can read for more details on these.

### Miscellaneous

[./ADT/miscellaneous/](Jump to `miscellaneous` folder. Click here.)

Data structures that serve a specific purpose. For example, I have defined a `matrix` data structure that exhibits the properties and behaviour of a matrix in linear algebra. There are some valid linear algebra operations that can be performed in `matrix` class.



## Updates

I will post updates here from this commit onwards.
* timestamp - 11212022 - I have implemented the pqueue dequeue method. I am not sure of its working however. I am checking from left first and then swapping immediately. This looks like a DFS approach. I might implement to look for the smallest element at the entire level and then make the swap.

* timestamp-11162022 - I am currently working on implementing a priority queue DS. The idea is to make it viable to use for our search algorithms such as UCS or A*. I am committing some progress on this DS but one of the functions in the pqueue DS is wrongly implemented and won't give any results
