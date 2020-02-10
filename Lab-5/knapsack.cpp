#include <iostream>
using namespace std;


class item {
  int id;
  int weight;
  int profit;
  bool visited;

  public :
  item() {}
  item(int id,int weight,int profit) {
    this -> id = id;
    this -> weight = weight;
    this -> profit = profit;
    this -> visited = false;
  }

  void display(){
    cout<<"\nID : "<<this->id<<"\n";
    cout<<"Weight : "<<this->weight<<"\n";
    cout<<"Profit : "<<this->profit<<"\n";
    cout<<"\n----\n";
  }

  void knapsack(item it[],int capacity,int n) {

    int x[n] = {0};
    int remainingCapacity = capacity;
    while(remainingCapacity >= 0) {
    int maxID = findMax(it,n);
    x[maxID] = 1;
    remainingCapacity-=it[maxID].weight;

  }

    for(int i=0; i<n; i++)
    cout<<x[i]<<"\t";

  }

  int findMax(item it[],int n) {
    int maxID = 0;
    int max = it[0].profit;

    for(int i=1; i<n; i++) {
      if(it[i].profit > max  && it[i].visited == false) {
        max = it[i].profit;
        maxID = it[i].id;
      }
    }

    it[maxID].visited = true;
    return maxID;
  }

};


int main() {
  item obj;
  int capacity,n,inputProfit,inputWeight;
  cout<<"Input capacity of knapsack\n"; cin>>capacity;
  cout<<"Input no. of items\n"; cin>>n;
  item it[n];
  cout<<"Input profit and weight for "<<n<<" items\n";
  for(int i=0; i<n; i++) {
    cin>>inputProfit;
    cin>>inputWeight;
    it[i] = item(i,inputProfit,inputWeight);
  }
  for(int i=0; i<n; i++) it[i].display();
  obj.knapsack(it,capacity,n);
}
