#include<iostream>
using namespace std;

void merge(int[],int,int,int);

void mergeSort(int arr[], int low, int high) {

  int mid = (low + high) / 2;
  mergeSort(arr,low,mid);
  mergeSort(arr,mid+1,high);
  merge(arr,low,mid,high);
}

void merge(int arr[], int low, int mid, int high) {
  if (low < high) {
  int x = 0,i,j;

  int left[10];
  int right[10];
  for(i =0; i<=mid; i++) left[x++] = arr[i]; left[x] = '\0';        x = 0;
  for(i =mid+1; i<=high; i++) right[x++] = arr[i]; right[x] = '\0'; x = 0;
  int result[10];
  i = 0;
  j = 0;
  while(left[i] != '\0' && right[j] != '\0') {
    if(left[i] < right[j]) {
      result[x++] = left[i];
      i++;
    }
    else {
      result[x++] = right[j];
      j++;
    }
  }

  while(left[i] != '\0') {
    result[x++] = left[i];
    i++;
  }
  while(right[j] != '\0') {
    result[x++] = right[j];
    j++;
  }
  right[x] = '\0';
  for(i = 0; result[i] != '\0'; i++)
    arr[i] = result[i];

}
}

int main() {
  int arr[] = {5,3,1,2,4};
  mergeSort(arr,0,4);
  for(int i=0; i<5; i++)
  cout<<arr[i]<<"\t";
}
