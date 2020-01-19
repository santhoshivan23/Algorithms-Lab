#include<iostream>
using namespace std;
#define MAX 20

class myStack {

  int top;
  int arr[20];
  public :
  myStack() {
    top = -1;
  }
  int push(int);
  int pop();
  int peek();
  void display();
};

int myStack :: push(int n) {

  if(top==MAX-1) return -1;
  arr[++top] = n;
  return n;
}

int myStack :: pop() {
  if(top==-1) return -1;
  return arr[top--];
}

int myStack :: peek() {
  if(top==-1) return -1;
  return arr[top];
}

void myStack :: display() {
  if(top==-1) cout<<"Stack empty!\n";
  for(int i=0;i<=top;i++)
  cout<<arr[i]<<"\t";
  cout<<endl;
}

int main() {
  int ch,n,res;
  myStack s;
  do{
    cout<<"\nStack Operations(1-4)\nPress any other key to exit\n1. Push\n2. Pop\n3. Peek\n4. Display\n";
    cin>>ch;
    switch(ch) {
      case 1 : cin>>n; res=s.push(n);
        if(res==-1) cout<<"Stack Overflow!";
        else cout<<"Pushed!";
        break;
      case 2 :
        if((res=s.pop())!=-1) cout<<res<<" popped!";
        else cout<<"Stack Underflow!";
        break;
      case 3 :
        if((res=s.peek())!=-1) cout<<res<<" is at top.";
        else cout<<"Stack Empty!";
        break;
      case 4 :
        s.display();
        break;

    }
  }while(ch>=1 && ch<=4);
}
