#include<iostream>
#include "./pqueue.h"

int main() {

    std::pair<int, int> data;
    pqueue pq;
    
    for(auto i : {1,2,3,4,5}) {
        data.first = i;
        std::cout<<data.first<<" - ";
        std::cin>>data.second;

        pq.enqueue(data);
    }
    
    pq.print();
    data = pq.dequeue();
    std::cout<<data.first<<" - "<<data.second;

    pq.print();
    return 0;
}