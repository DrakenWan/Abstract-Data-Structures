#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<time.h>
#define DTYPE int
#define floatGEN 1.1531

using namespace std;

void swap(int &a, int &b)
 {
     int temp;
     temp = a;
     a = b;
     b = temp;
 }

//edit as may suffice
class Sort {
    /* Sort algorithms in ascending order of their O() and T()



    */
        //edit datatype as may suffice
        // select data identifiers from standard library
        vector<DTYPE> data;
        int length;
		
		
		// helper functions for sorting algorithms
		void merge(vector<DTYPE>&);
		
    public:
        Sort() {
            this->length=0;
            }

        Sort(vector<DTYPE> data) {
            this->data = data;
            this->length = data.size();
        }
        
        void changeData(vector<DTYPE>);
        
		DTYPE *vec2array() {
			DTYPE arr[this->length];
			
			for(int i=0; i<this->length; i++)
			 arr[i] = this->data[i];
			 
			return arr;	
		}
		
        void reverse() {
            int i;
            for(i=0; i<length/2; i++)
                swap(this->data[i], this->data[length - 1 - i]);
        }

        // sorting algos better for low n values
        void insertion(bool);
        void bubble(bool); //O(n^2)
        void selection(bool); //O(n^2)

        // sorting algos for high / very high n values
        void mergeSort(bool); // O(logn) however if decr = true then O(n)

        void display();
};

void Sort::changeData(vector<DTYPE> data) {
    //update data altogether. No pushbacks to the vector
    this->data = data;
    cout<<endl<<"Updated Data."<<endl;
}

void Sort::display() {
    int i;
    for(i=0; i<this->length; i++)
        cout<<this->data[i]<<endl;
}

void Sort::insertion(bool decr=false) {

    int i, j, length = this->data.size();
    DTYPE temp;
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

void Sort::bubble(bool decr=false) {
    //O(n^2)
    int i, j;
    for(i=0; i<this->length - 1; i++)
     {
         for(j=0; j<this->length - 1 - i; j++)
          if (this->data[j] > this->data[j+1])
            swap(this->data[j], this->data[j+1]);
     }

     if(decr) //O(n)
        reverse();
}

void Sort::selection(bool decr=false) {
    //O(n^2)
    int i, j, min_index;
    for(i=0; i<this->length - 1; i++)
     {
         min_index = i;
         for(j=i+1; j<this->length; j++)
          if(this->data[j] < this->data[min_index])
            min_index = j;
         
         swap(this->data[i], this->data[min_index]);
     }

      if(decr) //O(n)
            reverse();

}


void Sort::merge(vector<DTYPE> &arr) {
	int len = arr.size();
	vector<DTYPE> L, R;
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
	
	
void Sort::mergeSort(bool decr=false) {
	
	vector<DTYPE> daa = this->data;
	
	merge(daa);
	
	this->data = daa;
	
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
	
    int length;
	vector<DTYPE> v;
    
    int max = 50, min = -20;
	
	srand(time(0));
    
    cout<<"Enter length of list:- "; cin>>length;
    for(int i=0; i<length; i++) {
    	DTYPE var = (rand()%max + min)*floatGEN;
    	v.push_back(var);
    }
    	

    Sort s(v);
    s.display();
    cout<<endl;
    s.mergeSort();
    s.display();
    return 0;
}