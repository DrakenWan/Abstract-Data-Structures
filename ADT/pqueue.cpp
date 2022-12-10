#include<iostream>
#include "./pqueue.h"

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
    data = pq.dequeue();
    cout<<data.first<<" - "<<data.second;

    pq.print();
    return 0;
}