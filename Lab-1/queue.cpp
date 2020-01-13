#include<iostream>
using namespace std;

#define MAX 20

class Q {
   int front;
   int rear;
   int arr[20];

   public :
   Q(){
     front = 0;
     rear = 0;
   }
   int enQ(int);
   int deQ();
   void display();
};


int Q :: enQ(int n) {
  if(rear == front-1 || (rear+1)%MAX == front) return -1;
  rear = (rear+1)%MAX;
  arr[rear] = n; cout<<rear;
  return n;
}

int Q :: deQ() {
  if(front == rear) return -1;
  return arr[++front];
}

void Q :: display() {
    if(front == 0 && rear == 0) cout<<"Queue is empty!\n";
  if(front > rear) {
    for(int i = front +1 ; i<=MAX-1 ; i++) cout<<arr[i]<<"\t";
  }
  else {
    for(int i=front+1; i<=rear ; i++) cout<<arr[i]<<"\t";
  }
}


int main() {
  int ch,n,res;
  Q q;
  do{
    cout<<"\nCircular Queue Operations(1-4)\nPress any other key to exit\n1. enQ\n2. deQ\n3. Display\n";
    cin>>ch;
    switch(ch) {
      case 1 : cin>>n; res=q.enQ(n);
        if(res==-1) cout<<"Queue Overflow!";
        else cout<<"Enqueued!";
        break;
      case 2 :
        if((res=q.deQ())!=-1) cout<<res<<" deQueued!";
        else cout<<"Queue Underflow!";
        break;
      case 3 :
        q.display();

        break;

    }
  }while(ch>=1 && ch<=4);
}
