#include<iostream>
#include<vector>
#define dtype int
#define dtype_smpl 0 //give a sample dtype value here for reference
using namespace std;


// min heap representation used
class pqueue {
        vector< pair<dtype, int> > data;
        void swap(pair<dtype, int>&, pair<dtype, int>&);

    public:
        bool isEmpty() {
            if(this->data.size() == 0)  return true;
            return false;
        }

        void enqueue(pair<dtype, int>);
        pair<dtype, int> dequeue(bool verbose=false);
        pair<dtype, int> peek();
        void print();
};

pair<dtype, int> pqueue::peek() {
    if(this->data.size() == 0) {
        cout<<"Pqueue is empty.";
        pair<dtype, int> s(dtype_smpl,0); //not a generalized value returned //change it later
        return s;
    }
    return this->data[0];
}

void pqueue::enqueue(pair<dtype, int> value) {
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

pair<dtype, int> pqueue::dequeue(bool verbose) {

    // I will swap last element with the root and then pop the root swapped to last
    // and then to maintain the pqueue invariant do what is required
    int last = this->data.size() - 1; 
    pair<dtype, int> root(dtype_smpl, 0); 

    // if pqueue is empty
    if(last < 0)  {
        cout<<"ERROR; There are no elements in the queue.";
        return root;
    }
    this->swap(this->data[0], this->data[last]);
    root = this->data[last];
    if(verbose) cout<<"Element "<<root.first<<" with priority "<<root.second<<".\n";

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
        else if( child2 < this->data.size() && this->data[child2].second < this->data[lidx].second ) 
        {
            swap(this->data[child2], this->data[lidx]);
            lidx = child2;
        }
        else {
            return root;
        }
        child1 = (lidx+1)*2 - 1;
        child2 = (lidx+1)*2;
        
    } //while loot
}

void pqueue::swap(pair<dtype, int> &a, pair<dtype, int> &b) {
    pair<dtype, int> temp = a;
    a = b;
    b = temp;
}


void pqueue::print() {
    
    cout<<endl<<"[";
    for(auto i : this->data)
        cout<<"("<<i.first<<","<<i.second<<")";
    cout<<"]"<<endl;
}
