#include<iostream>

using namespace std;

template <typename any>
int ternarySearch(int l, int r, int search, any array[]) {
	
	if ( r>=l) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		
		if(array[mid1] == search) {
			return mid1;
		}
		
		if(array[mid2] == search) {
			return mid2;
		}
		
		
		
		if (search < array[mid1]) {
			return ternarySearch(l, mid1 - 1, search, array);
		} else if ( search > array[mid2]) {
			return ternarySearch(mid2 + 1, r, search, array);
		} else {
			return ternarySearch(mid1 + 1, mid2 - 1, search, array);
		}
	}
	
	
	return -1;
}

int main() {
	
	long int l, r, p, ele;
	
	// array must be sorted
	// keep the 1d array in r x 6 form
	long int arr[] = { -4, -2, 4, 4, 4, 5,
				   8, 8, 9, 10, 12, 100,
				   156, 178, 199, 199,  200, 777,
				   845, 856, 888, 923, 923, 925};
	
	int length = 24;
	l = 0; r = length - 1;
	
	cout<<"Enter the number you want to look up: ";
	cin>>ele;
	
	
	p = ternarySearch(l, r, ele, arr);
	
	if (p == -1) cout<<"Could not find "<<ele;
	else cout<<"Found "<<ele<<" at index "<<p;
	
	return 0;
}