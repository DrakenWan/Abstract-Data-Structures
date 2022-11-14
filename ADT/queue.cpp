/* queue implementation 

  Author: Karry Kaul
*/

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
			if(this->verbose) x = *(this->data.begin());
			this->data.erase(this->data.begin());
			if(this->verbose) cout<<endl<<x<<" deleted.\n";
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

int main() {
	
	queue _;
	_.enqueue(10);
	_.enqueue(20);
	_.enqueue(30);
	_.enqueue(49);
	_.enqueue(50);
	
	_.display();
	
	_.dequeue();
	_.display();
	
	return 0;
}