#include<iostream>
using namespace std;

class container {
  int id;
  int weight;
  public :
  container(){}
  container(int id,int weight) {
    this -> id = id;
    this -> weight = weight;
  }
  void display() {
    cout<<this->id<<" "<<this->weight<<"  ";
  }
  void sort(container c[],int n) {
    for(int i=1; i<n ; i++) {
      for(int j=0 ; j<n-1; j++) {
        if(c[j].weight > c[j+1].weight) {
          container temp  = c[j+1];
          c[j+1] = c[j];
          c[j] = temp;
        }
      }
    }

  }

  void load(container c[],int n,int capacity,int result[]) {
    for(int i=0; i<n; i++) {
      if(c[i].weight <= capacity) {
        result[c[i].id] = 1;
        capacity-=c[i].weight;
      }
    }
  }

};

int main() {

  container obj;
  int capacity,n,inputWeight;
  container c[n];
  int result[n] = {0};
  cout<<"Input maximum capcity of ship\n";
  cin>>capacity;
  cout<<"Input no. of containers to be loaded\n";
  cin>>n;
  cout<<"Input weight of "<<n<<" containers (space seperated integers)\n";
  for(int i=0; i<n; i++) {
    cin>>inputWeight;
    c[i]=container(i,inputWeight);
  }
  obj.sort(c,n);
  obj.load(c,n,capacity,result);
  for(int i=0 ;i<10; i++)
  cout<<result[i]<<"\t";
  cout<<"\n";


}
