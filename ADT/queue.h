#pragma once
#include<vector>


template<typename S>
class queue {
	std::vector<S> data;

	int verbose;
	/*
		front is this->data.begin()
		rear is this->data.end()
	*/
	
	public:
		queue(int verbose=0) {
			this->verbose=verbose;
			if(this->verbose) std::cout<<"Queue created!\n";
		}
		
		void enqueue(S val) {
			data.push_back(val);
		} 
		
		S dequeue() {
			S x;
			x = this->data[0];
			this->data.erase(this->data.begin());
			this->data.shrink_to_fit();
			if(this->verbose) std::cout<<std::endl<<x<<" deleted.\n";
			return x;
		}
		
		bool isEmpty() {
			if(this->data.size() > 0)
				return false;
			return true;	
		}

		void display() {
			if(this->verbose) std::cout<<"Queue Data:- ";
			std::cout<<"\n[(front)-->  ";
			for(auto i = this->data.begin(); i != this->data.end(); ++i) {
					std::cout<<*i<<"  ";
			}
			std::cout<<"  <--(rear)]";
		}
};