#include<iostream>
using namespace std;
#define null 0
class Node {
	int data;
	Node* next;

public:
	void insertatEnd(int n);
	void insertAfterNode(int b, int n);
	void insertBeforeNode(int b, int n);
	void deleteLastNode();
	void deleteSpecific(int n);
	void deleteSpecificNode(int n);
	void deleteAlternate();
	void reverse();
	void sort();
	void insertIntoSorted(int n);
	void traverse();

};

Node* first = null;
Node* i;

void Node::insertatEnd(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = null;
	if(first==null){
		first=temp;
	}
	else {

		for(i=first;i->next!=null;i=i->next);
			i->next=temp;
	}

}

void Node::deleteLastNode() {
	if(first==null) cout<<"List is empty!";
	else if(first->next==null) {
		Node* temp = first;
		first=null;
		delete temp;
	}

	else {
	Node* prev;
	for(i=first;i->next!=null;i=i->next)
		prev=i;
	prev->next=null;
	delete i;


	}
}

void Node::traverse(){
	if(first==null) cout<<"List is empty!";
	else {
cout<<"   ";
		for(i=first;i!=null;i=i->next) {
			cout<<" "<<i->data<<" "<<"--->";

		}
		cout<<"NULL";
	}
}

void Node::insertAfterNode(int b, int n) {
int flag=0;
for(i=first;i!=null;i=i->next){
   if(i->data==b){
    flag=1;
    Node* temp= new Node;
    temp->data=n;
    temp->next=i->next;
    i->next=temp;
    break;
   }
}
if(flag==0) cout<<"Node NOT found!";

}

void Node::insertBeforeNode(int b, int n) {
Node* prev;
if(first->data==b){
    Node* temp = new Node;
    temp->data=n;
    temp->next=first;
    first=temp;

}
else {
for(i=first;i&&i->data!=b;i=i->next){
    prev=i;
}
if(!i){
    cout<<b<<" not present in the list ";
return;
}
Node* temp=new Node;
temp->data=n;

temp->next=i;
prev->next=temp;

}
}

void Node::deleteSpecific(int n){

    if(first->data == n) {
        Node* temp;
        temp=first;
        first=first->next;
        delete temp;
    }
    else {
Node* prev; int flag=0;
for(i=first;i&&i->data!=n;i=i->next){
    prev=i;

}
if(i==null) cout<<n<<" not found!";
prev->next=i->next;
delete i;
    }
}

void Node::deleteSpecificNode(int n){


    int count=1; Node* prev;
    for(i=first;i!=null&&count!=n;i=i->next,count++)
    prev=i;

prev->next=i->next;
delete i;

}

void Node::deleteAlternate() {
int count=0;

for(i=first;i!=null;i=i->next,count++);
for(int x=2;x<=count;x++)
{
    deleteSpecificNode(x);
    count--;
}
}

void Node::reverse() {
Node* curr=null;
Node* prev=null;

while(first!=null) {
    curr=first;
    first=first->next;
    curr->next=prev;
    prev=curr;

}
first=curr;
}

void Node::sort() {
	Node* j; int temp;

	for(i=first;i->next!=null;i=i->next) {
		for(j=i->next;j!=null;j=j->next) {
			if(j->data<i->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}

void Node::insertIntoSorted(int n) {
	Node* temp=new Node;
	temp->data=n;
	if(first->data > n) {

        temp->next=first;
        first=temp;
	}
	else {
	int flag=0;
for(i=first;i->next!=null;i=i->next){

		if(i->data<=n && i->next->data>=n) {

			temp->next=i->next;
			i->next=temp;
			flag=1;
			break;
		}

}
if(flag==0){
	insertatEnd(n);
}
	}
}


int main(){
	Node List;
	int ref; char choice='A';
	int key;

while(choice>='A'&&choice<='I') {

	cout<<"A. Insert at end of list\nB. Insert before a node\nC. Insert after a node\nD. Delete a specific value\n";
	cout<<"E. Display\nF. Reverse\nG. Bubble Sort \nH. Delete alternate nodes\n";
	cout<<"I. Assuming sorted list, insert value";
	cout<<"\n\nEnter choice\n";
  cin>>choice;

	switch(choice) {
		case 'B' :
		cout<<"Input node and value\n";
		cin>>ref>>key;
		List.insertBeforeNode(ref,key);
		List.traverse(); break;

		case 'C' :
		cout<<"Input node and value : \n";
		cin>>ref>>key;
		List.insertAfterNode(ref,key); List.traverse(); cout<<endl; break;

		case 'D' :
		cout<<"Input deletion value:"; cin>>key;
		List.deleteSpecific(key); List.traverse(); cout<<endl; break;

		case 'E' : List.traverse(); cout<<endl; break;

		case 'F' : List.reverse(); List.traverse(); cout<<endl; break;

		case 'G' : List.sort(); List.traverse(); cout<<endl; break;

		case 'H' : List.deleteAlternate(); List.traverse(); cout<<endl; break;

		case 'I' : cout<<"*SORTED LIST ASSUMED*\nInput value :\n"; cin>>key;
		List.insertIntoSorted(key);List.traverse(); cout<<endl; break;

		case 'A' : cout<<"Input insertion key\n"; cin>>key; List.insertatEnd(key); List.traverse(); cout<<endl; break;

	}

}

}
