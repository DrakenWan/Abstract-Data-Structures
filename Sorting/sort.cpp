#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>



using namespace std;


//edit as may suffice
template<typename S>
class Sort {
    /* Sort algorithms in ascending order of their O() and T()



    */
        //edit datatype as may suffice
        // select data identifiers from standard library
        vector<S> data;
        long length;
		
		
		// helper functions for sorting algorithms
		void merge(vector<S>&);
		long partition(vector<S>&, long, long);
		void quick(vector<S>&, long, long);
		void swap(S &a, S &b)
        {
            S temp;
            temp = a;
            a = b;
            b = temp;
        }


        void returnSortedArray() {
            return this->data;
        }

    public:
        Sort() {
            this->length=0;
            }

        Sort(vector<S> data) {
            this->data = data;
            this->length = data.size();
        }
        

        void changeData(vector<S>);
		void changeData(S val, long idx) {
            if(idx < this->length)
                this->data[idx] = val;
        }

        void addData(S val) {
            this->data.push_back(val);
            this->length = this->data.size();
        }
        
        void reverse() {
            long i;
            for(i=0; i<length/2; i++)
                this->swap(this->data[i], this->data[length - 1 - i]);
        }

        // sorting algos better for low n values
        void insertion(bool decr=false);
        void bubble(bool decr=false); //O(n^2)
        void selection(bool decr=false); //O(n^2)

        // sorting algos for high / very high n values
        void mergeSort(bool decr=false); // O(logn) however if decr = true then O(n)
		void quickSort(bool decr=false); //O(logn) however if decr = true then O(n)
        void display();
};

template<typename S>
void Sort<S>::changeData(vector<S> data) {
    //update data altogether. No pushbacks to the vector
    this->data = data;
    this->length = data.size();
    //cout<<endl<<"Updated Data."<<endl;
}


template<typename S>
void Sort<S>::display() {
    long i;
    cout<<"[";
    for(i=0; i<this->length; i++) {
        cout<<this->data[i];
        if(this->length-1 > i) cout<<", ";
    }
    cout<<"]";
}

template<typename S>
void Sort<S>::insertion(bool decr) {

    long i, j, length = this->data.size();
    S temp;
    //cout<<length;

    for(i=1; i<length; i++)
     {
         j = i - 1;
         temp = this->data[i];
         while(j > -1 && temp < this->data[j]) {
            this->data[j+1] = this->data[j];
            j--;
         }
         this->data[j+1] = temp;
     }

     if(decr) // O(n)
        reverse();
}

template<typename S>
void Sort<S>::bubble(bool decr) {
    //O(n^2)
    long i, j;
    for(i=0; i<this->length - 1; i++)
     {
         for(j=0; j<this->length - 1 - i; j++)
          if (this->data[j] > this->data[j+1])
            this->swap(this->data[j], this->data[j+1]);
     }

     if(decr) //O(n)
        reverse();
}

template<typename S>
void Sort<S>::selection(bool decr) {
    //O(n^2)
    long i, j, min_index;
    for(i=0; i<this->length - 1; i++)
     {
         min_index = i;
         for(j=i+1; j<this->length; j++)
          if(this->data[j] < this->data[min_index])
            min_index = j;
         
         this->swap(this->data[i], this->data[min_index]);
     }

      if(decr) //O(n)
            reverse();

}


template<typename S>
void Sort<S>::merge(vector<S> &arr) {
	long len = arr.size();
	vector<S> L, R;
	if(len > 1) {
		
		int mid = len/2;
		
		for(int i=0; i<mid; i++)
			L.push_back(arr[i]);
		
		for(int i=mid; i<len; i++)
			R.push_back(arr[i]);
			
		merge(L);
		
		merge(R);
		
		int i,j,k;
		i=j=k=0;
		
		while(i < L.size() && j < R.size()) {
			
			if (L[i] < R[j]) {
				arr[k] = L[i];
				i+=1;
			}
			else {
				arr[k] = R[j];
				j+=1;
			}
		
		k +=1;
		}
		
		while (i < L.size()) {
			arr[k] = L[i];
			i++; k++;
		}
		
		while(j < R.size()) {
			arr[k] = R[j];
			j++;
			k++;
		}
		
		
	} // OUTERMOST IF CONDITION ENDS
} //MERGE function
	

template<typename S>
void Sort<S>::mergeSort(bool decr) {
	
	vector<S> daa = this->data;
	
	merge(daa);
	
	this->changeData(daa);
	
	if(decr) //O(n)
		reverse();
}


// quicksort methods
template<typename S>
long Sort<S>::partition(vector<S> &arr, long low, long high) {
	
	S pivot = arr[high];
	
	long i = low - 1;
	
	for(long j=low; j<high; j++)
		if( arr[j] < pivot) {
			
			i++;
			this->swap( arr[i], arr[j]);
		}
	
	this->swap(arr[i+1], arr[high]);
	
	return i+1;
}

template<typename S>
void Sort<S>::quick(vector<S> &arr, long low, long high) {
	
	if( low < high ) {
		
		long pidx = partition(arr, low, high);
		
		quick(arr, low, pidx - 1); //left of pivot
		quick(arr, pidx + 1, high); //right of pivot
	}
	
}

template<typename S>
void Sort<S>::quickSort(bool decr) {
	vector<S> daa = this->data;
	
	quick(daa, 0, daa.size()-1);
	
	this->changeData(daa);
	
	if(decr) //O(n)
	 	reverse();
	
}


int main() 
{
	// currently programmed DTYPE to int
	// the main driver function is coded to handle
	// the numerical data types (like int, short, double
	//  float, etc.) (take a look at the for loop
	// below)
	
    long length;
	vector<int> v;

    Sort<int> s;
    s.addData(10);
    s.addData(1);
    s.addData(-1);
    s.addData(21);
    s.addData(5);
    s.addData(7);
    s.addData(10);
    s.addData(-5);

    s.display();
    s.changeData(0, 2);
    cout<<endl;
    s.quickSort();
    s.display();
    cout<<"\n\n\n";
    
    return 0;
}