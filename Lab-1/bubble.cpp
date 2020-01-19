#include<iostream>

using namespace std;

int main() {

int arr[] = {50,40,30,20,10};

for(int i=1;i<5;i++) {
   for(int j=0; j<4;j++) {
	if(arr[j]>arr[j+1]) {
	int temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp; 
}
}

}

for(int i=0;i<5;i++) cout<<arr[i]<<"\t";

cout<<endl;

}
