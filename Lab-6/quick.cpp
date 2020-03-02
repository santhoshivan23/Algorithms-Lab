#include<iostream>
using namespace std;

void quick(int arr[], int low, int high) {
  if(low < high) {
    int pivot = low;
    int i = low +1;
    int j = high;
    int temp;

    while(true) {

      while(arr[i] < arr[pivot]) i++;
      while(arr[j] > arr[pivot]) j--;
      if(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      else break;
    }

    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    quick(arr,low,pivot-1);
    quick(arr,pivot+1,high);
}

}


int main() {

  int n;
  cout<<"Input no. of elements\n";
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
  cin>>arr[i];
  quick(arr,0,n-1);
  for(int i=0; i<n; i++)
  cout<<arr[i]<<"\t";
  cout<<"\n";

}
