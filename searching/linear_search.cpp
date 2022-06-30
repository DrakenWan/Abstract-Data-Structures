// Author: Kartikay Kaul
// Linear Search

#include<iostream>

using namespace std;

template <typename any>
int linear_search(any ele, any data[], int len) {

    for(int i=0; i<len; i++) {
        if(data[i] == ele) {
            cout<<"Found result: "<<ele<<" at position "<<i<<".";
            return i;
        }
    }
    cout<<"Couldn't find "<<ele<<".\n";
    return -1;
}


int main() {
    
    cout<<"Finding names in a list";
    string names[] = {	// Maintain this array in R x 4 matrix form where R is row length
						"Akriti", "Angelina", "Anda", "Andou",
    				  	"Smoke", "Carl", "Denise", "Daisy",
					  	"Doora", "Egg", "Eddy", "Babe", 
					  	"Xanther", "Nicki", "Kale",  "Zairi",
					  	"Wu", "Ming", "Shinzo",  "Ike",
					   	"Emil", "Jakub", "Shanti", "Manish"};
    
    int rows = 6;
    int length = rows * 4;
    char choice;
   	string name;
    do {
    	cout<<"\n\nEnter the name you want: ";
	    cin>>name;
	    
	    int loc = linear_search(name, names, length);
	    //cout<<endl<<loc;
	    
	    
	    cout<<"\nKeep Looking? (Y/n)";
	    cin>>choice;
	} while(choice == 'Y' || choice == 'y');
    
    return 0;
}