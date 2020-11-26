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
        void insertion(bool);
        void display();
};


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

     if(decr) { //O(n)
         for(i=0; i<length/2; i++)
            swap(this->data[i], this->data[length - 1 - i]);
     }
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
    s.insertion(true);
    s.display();
    return 0;
}