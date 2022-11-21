#include<iostream>
#include<vector>
#define dtype int
#define dtype_smpl 0 //give a sample dtype value here for reference
#define _MAXIMUMPRIORITY_ 30000
using namespace std;


// min heap execution
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
        pair<dtype, int> s(dtype_smpl,0); //not a generalized value returned
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

    //swapping the max(root) with last leaf node. then pop out the max from the end
    // it is kind of like popping the prioritised node from front of pq

    // I will swap last element with the root and then pop the root swapped to last
    // and then to maintain the pqueue invariant do what is required
    int last = this->data.size() - 1;
    this->swap(this->data[0], this->data[last]);
    this->data.pop_back();
    
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

int main() {

    pair<dtype, int> data;
    pqueue pq;
    
    for(auto i : {1,2,3,4,5}) {
        data.first = i;
        cout<<data.first<<" - ";
        cin>>data.second;

        pq.enqueue(data);
    }
    
    pq.print();
    
    return 0;
}