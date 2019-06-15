#include<iostream>

using namespace std;

//bubble sort
void bsort(int *arr, int len, int order=0)
{
  //order = 0 increasing
  //order = 1 decreasing
  int i, j, temp;
  if(order == 0)
  {
      for(i=0; i<len-1; i++)
           for(j=0; j<len-i-1; j++)
                if(*(arr+j) > *(arr+j+1))
                {
                    temp = *(arr+j);
                    *(arr+j) = *(arr+j+1);
                    *(arr+j+1) = temp;
                }
  }
  else
  {
      for(i=0; i<len-1; i++)
           for(j=0; j<len-i-1; j++)
                if(*(arr+j) < *(arr+j+1))
                {
                    temp = *(arr+j);
                    *(arr+j) = *(arr+j+1);
                    *(arr+j+1) = temp;
                }
  }

}

//binary search iterative
template<typename Searchable>
int binarySearch(Searchable *arr, int len, Searchable ele)
{
  int mid,low = 0, high = len;

  while(low <= high)
  {
      mid = (low+high)/2;
      if(ele == *(arr+mid))
           return mid;
      else if(ele < *(arr+mid))
           high = mid-1;
      else
          low = mid+1;
  }

  return -1;
}

int main(int argc, char **argvs)
{
    int i, length;
    cout<<"Enter the length of list:";
    cin>>length;
    int *arr = new int[length];
    
    cout<<"Enter the numbers:\n";
    for(i=0; i<length; i++)
        cin>>*(arr+i);
    
    bsort(arr,length);
    
    cout<<"\nSorted list is:\n";
    for(i=0; i<length; i++)
        cout<<*(arr+i)<<endl;

    //now binary search
    int n = argc;
    cout<<"Found at array position "<<binarySearch(arr,length,n);
    cout<<"\nFound at array position "<<binarySearch(arr,length,69);
    return 0;
}