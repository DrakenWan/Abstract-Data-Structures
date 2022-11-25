#define dtype int

using namespace std;

template<typename S>
class queue {
	vector<S> data;

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
		
		void enqueue(S val) {
			data.push_back(val);
		} 
		
		S dequeue() {
			S x;
			x = this->data[0];
			this->data.erase(this->data.begin());
			this->data.shrink_to_fit();
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