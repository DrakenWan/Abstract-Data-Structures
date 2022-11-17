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
    int lidx = this->data.size() - 1;

    // check of condition if the index is out of bounds and compare the parent with child
    // while above condn is true do swaps
    while(lidx > -1 && lidx/2+1 > -1 && this->data[lidx].second < this->data[lidx/2 + 1].second)
     {
        this->swap(this->data[lidx], this->data[lidx/2 + 1]);
        lidx /= 2;
     }
}

pair<dtype, int> pqueue::dequeue(bool verbose) {

    //swapping the max(root) with last leaf node. then pop out the max from the end
    // it is kind of like popping the prioritised node from front of pq
    swap(*(this->data.begin()), *(this->data.end()));
    if(verbose) cout<<(this->peek()).first;
    this->data.pop_back();

    int ti = 0;
    while(ti < this->data.size()) {
        
        if( ((ti+1)*2 - 1) < this->data.size())
        {
            int mini = (ti+1)*2 - 1;
            if ( mini+1 < this->data.size() )
                if(this->data[mini+1].second < this->data[mini].second )
                    mini = mini+1;
            
            if(this->data[ti] < this->data[mini])
                {
                    swap(this->data[ti], this->data[mini]);
                    ti = mini;
                }
        }   
    }
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
        cin>>data.second;

        pq.enqueue(data);
    }
    
    pq.print();
    
    return 0;
}