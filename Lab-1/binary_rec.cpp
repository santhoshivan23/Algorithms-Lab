#include<iostream>
using namespace std;

int binarySearch(int[],int,int,int);

int main() {

int arr[] = {10,20,30,40,50};
int key;
cout<<"Input key\n";
cin>>key;

int index = binarySearch(arr,key,0,4);
if(index==-1) cout<<"Not Found!\n";
else cout<<key<<" found at index "<<index<<"\n";


}


int binarySearch(int arr[],int key,int low,int high) {

  if(low>high) return -1;
  int mid = (low + high)/2;
  if(arr[mid]==key) return mid;
  else if(arr[mid] < key) return binarySearch(arr,key,mid+1,high);
  else return binarySearch(arr,key,low,mid-1);


}
