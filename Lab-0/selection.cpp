#include<iostream>

using namespace std;

int main() {

int arr[] = {50,40,30,20,10};



for(int i=0;i<4;i++) {
  int index = i;
for(int j=i+1;j<5;j++) {

if(arr[j] < arr[index]) {
index = j;

}

}

int temp = arr[i];
arr[i] = arr[index];
arr[index] = temp;

}

for(int i=0;i<5;i++)
cout<<arr[i]<<"\t";
cout<<endl;

}
