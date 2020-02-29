#include<iostream>
#define INFINITY 9999

using namespace std;

class graph {
  int v;
  int adj[100][100];

  public :
    graph(int v);
    void addEdge(int,int,int);
    void prims();
    int findMinKey(int[],bool[]);
    void printTree(int[],int[]);


};


graph::graph(int v) {
  this -> v = v;
  for(int i=0; i<v; i++)
    for(int j=0; j<v; j++)
      adj[i][j] = 0;
}


void graph :: addEdge(int from, int to, int weight) {
  adj[from][to] = weight;
  adj[to][from] = weight;
}

void graph :: prims() {

  int parent[v];
  bool included[v];

  int key[v];
  for(int i=0 ;i<v; i++)
  included[i] = false, key[i] = INFINITY;

  parent[0] = -1;
  key[0] = 0;

  for(int i=0; i<v-1; i++) {

    int u =findMinKey(key,included);
    included[u] = true;
    for(int x=0; x<v; x++)
      if(adj[u][x]!=0 && !included[x] && adj[u][x] < key[x])
        key[x] = adj[u][x], parent[x] = u;
  }

  printTree(parent,key);
}

int graph :: findMinKey(int key[], bool included[]) {
  int min = INFINITY;
  int minIndex;
  for(int i=1; i<v; i++)
    if(key[i] < min && !included[i])
      min = key[i], minIndex = i;

  return minIndex;
}

void graph :: printTree(int parent[],int key[]) {

  cout<<"Selected Edges\tWeight\n";
  for(int i=1; i<v; i++)
    cout<<parent[i]<<"->"<<i<<"\t\t"<<adj[parent[i]][i]<<"\n";

}


int main() {

  graph g(9);
  g.addEdge(0,1,4);
  g.addEdge(0,7,8);
  g.addEdge(1,2,8);
  g.addEdge(1,7,11);
  g.addEdge(7,8,7);
  g.addEdge(7,6,1);
  g.addEdge(2,8,2);
  g.addEdge(6,8,6);
  g.addEdge(5,6,2);
  g.addEdge(3,5,14);
  g.addEdge(2,5,4);
  g.addEdge(2,3,7);
  g.addEdge(3,4,9);
  g.addEdge(4,5,10);
  g.prims();



}
