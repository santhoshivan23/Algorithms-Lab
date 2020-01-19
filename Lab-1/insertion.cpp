#include<iostream>
using namespace std;

int main() {

int arr[] = {50,40,30,20,10};


int i, key, j;
    for (i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }

for(int x=0;x<5;x++)
  cout<<arr[x]<<"\t";
cout<<endl;


}
