#include<iostream>
using namespace std;

int main() {

int arr[] = {10,20,30,40,50};
int key,index=-1;
cout<<"Input key\n";
cin>>key;
for(int i=0; i<5; i++) {
if(arr[i]==key) {
index = i;
break;
}
} 

if(index!=-1) cout<<key<<" found at index "<<index<<"\n";
else cout<<"Not Found\n";

}
