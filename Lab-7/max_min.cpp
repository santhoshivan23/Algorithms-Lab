#include<iostream>
using namespace std;

int findMax(int[],int,int);
int findMin(int[],int,int);

int main() {
  int n,max,min;
  cout<<"Input no. of elements\n";
  cin>>n;
  int arr[n];
  cout<<"Input elements\n";
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  max = findMax(arr,0,n-1);
  min = findMin(arr,0,n-1);
  cout<<"The maximum element is "<<max<<"\nThe minimum element is "<<min<<"\n";
}

int findMax(int arr[], int low, int high) {
  if(low == high) return arr[low];
  int mid = (low + high) / 2;
  int maxLeft = findMax(arr,0,mid);
  int maxRight = findMax(arr,mid+1,high);
  return (maxLeft > maxRight) ? maxLeft : maxRight;
}

int findMin(int arr[], int low, int high) {
  if(low == high) return arr[low];
  int mid = (low + high) / 2;
  int minLeft = findMin(arr,0,mid);
  int minRight = findMin(arr,mid+1,high);
  return (minLeft < minRight) ? minLeft : minRight;
}
