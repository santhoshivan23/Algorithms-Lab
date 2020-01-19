#include<iostream>
using namespace std;

int main() {

int arr[] = {10,20,30,40,50};
int key,index=-1;
cout<<"Input key\n";
cin>>key;
int low = 0,high = 4;

while(low<=high) {

int mid = (low+high)/2;

if(key < arr[mid]) high = mid-1;
else if (key > arr[mid]) low = mid+1;
else {index = mid; break;}

}


if(index==-1) cout<<"Not Found!\n";

else cout<<key<<" found at index "<<index<<"\n";


}
