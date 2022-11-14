#include<iostream>
#include<vector>
#define dtype int

using namespace std;


class queue {
	vector<dtype> data;

	int verbose;
	/*
		front is this->data.begin()
		rear is this->data.end()
	*/
	
	public:
		queue(int verbose=0) {
			this->verbose=verbose;
			if(this->verbose) cout<<"Queue created!\n";
		}
		
		void enqueue(dtype val) {
			data.push_back(val);
		} 
		
		dtype dequeue() {
			dtype x;
			x = *(this->data.begin());
			this->data.erase(this->data.begin());
			if(this->verbose) cout<<endl<<x<<" deleted.\n";
			return x;
		}
		
		bool isEmpty() {
			if(this->data.size() > 0)
				return false;
			return true;	
		}

		void display() {
			
			if(this->verbose) cout<<"Queue Data:- ";
			cout<<"\n[(front)-->  ";
			for(auto i = this->data.begin(); i != this->data.end(); ++i) {
					cout<<*i<<"  ";
			}
			cout<<"  <--(rear)]";
		}
};