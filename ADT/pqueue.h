#pragma once
#include<iostream>
#include<vector>




// min heap representation used
template<typename S>
class pqueue {
        std::vector< std::pair<S, int> > data;
        void swap(std::pair<S, int>&, std::pair<S, int>&);

    public:
        bool isEmpty() {
            if(this->data.size() == 0)  return true;
            return false;
        }

        void enqueue(std::pair<S, int>);
        std::pair<S, int> dequeue(bool verbose=false);
        std::pair<S, int> peek();
        void print();
};

template<typename S>
std::pair<S, int> pqueue<S>::peek() {
    if(this->data.size() == 0) {
        std::cout<<"Pqueue is empty.";
        std::pair<S, int> s(S(),0); //not a generalized value returned //change it later
        return s;
    }
    return this->data[0];
}

template<typename S>
void pqueue<S>::enqueue(std::pair<S, int> value) {
    // insert at the end
    this->data.push_back(value);

    // compare and swap child with parent if child smaller than parent
    int lidx = this->data.size() - 1, parentidx=(lidx+1)/2 - 1;

    // check of condition if the index is out of bounds and compare the parent with child
    // while above condn is true do swaps
    
    while(lidx > -1 && parentidx > -1 && this->data[lidx].second < this->data[parentidx].second)
     {
        this->swap(this->data[lidx], this->data[parentidx]);
        lidx = parentidx;
        parentidx = (lidx+1)/2-1;
     }
}

template<typename S>
std::pair<S, int> pqueue<S>::dequeue(bool verbose) {

    // I will swap last element with the root and then pop the root swapped to last
    // and then to maintain the pqueue invariant do what is required
    int last = this->data.size() - 1; 
    std::pair<S, int> root(S(), 0); 

    // if pqueue is empty
    if(last < 0)  {
        std::cout<<"ERROR; There are no elements in the queue.";
        return root;
    }
    this->swap(this->data[0], this->data[last]);
    root = this->data[last];
    if(verbose) std::cout<<"Element "<<root.first<<" with priority "<<root.second<<".\n";

    this->data.pop_back(); //remove last element
    this->data.resize(last); //reduce size/capacity of vector ds

    // maintaining pqueue invariant
    /*   
        Algorithm
            set lidx = 0
            set child1 = (lidx + 1) * 2 - 1
            set child2 = (lidx+1)*2
            while lidx < size
                if child1 < lidx and child1 < size
                then swap
                     lidx = child1
                     enumerate child1, child2
                
                if child2 < lidx and child2 < size
                then swap
                     lidx = child2
                     enumerate child1, child2    
    */
    int lidx = 0, child2 = (lidx+1)*2, child1 = (lidx+1)*2 - 1;

    while(lidx < this->data.size()) {
        if( child1 < this->data.size() && this->data[child1].second < this->data[lidx].second)
        {
            swap(this->data[child1], this->data[lidx]);
            lidx = child1;
        }
        else  {
            if( child2 < this->data.size() && this->data[child2].second < this->data[lidx].second ) 
            {
                swap(this->data[child2], this->data[lidx]);
                lidx = child2;
            }
            else {
                return root;
            }
        }
        child1 = (lidx+1)*2 - 1;
        child2 = (lidx+1)*2;
        
    } //while loot

    return root;
}

template<typename S>
void pqueue<S>::swap(std::pair<S, int> &a, std::pair<S, int> &b) {
    std::pair<S, int> temp = a;
    a = b;
    b = temp;
}

template<typename S>
void pqueue<S>::print() {
    
    std::cout<<std::endl<<"[";
    for(auto i : this->data)
        std::cout<<"("<<i.first<<","<<i.second<<")";
    std::cout<<"]"<<std::endl;
}
