#include<iostream>
#include<vector>
#include<string>

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
        vector<int> data;
        int length;

    public:
        Sort() {
            this->length=0;
            }

        Sort(vector<int> data) {
            this->data = data;
            this->length = data.size();
        }
        
        void changeData(vector<int>);

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
        void merge(bool); // O(logn) however if decr = true then O(n)

        void display();
};

void Sort::changeData(vector<int> data) {
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

    int i, j , temp, length = this->data.size();
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

int main()

{
    //int a = 10;
    //cout<<a;

    // init the dummy data vector
    vector<int> v;
    v.push_back(10);
    v.push_back(2);
    v.push_back(3);
    v.push_back(23);
    v.push_back(0);
    v.push_back(8);
    v.push_back(11);
    v.push_back(1);
    v.push_back(-1);

    Sort s(v);
    s.display();
    cout<<endl;
    s.selection();
    s.display();
    return 0;
}