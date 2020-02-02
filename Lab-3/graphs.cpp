#include<iostream>
using namespace std;

class graph {
  int v;
  int adj[100][100];

  public :
    graph(int v);
    void addEdge(int from, int to);
    void printGraph();
    void bfs(int source);
    void dfs(int source);
    void transpose();
    void filterOdd(int);
    void filterEven(int);
    void printAllPaths(int,int);
    void printAllPathsHelper(int,int,bool[],int[],int);
    bool pathExists(int,int);
    bool isConnected();
};


graph::graph(int v) {
  this -> v = v;
  for(int i=0; i<v; i++)
    for(int j=0; j<v; j++)
      adj[i][j] = 0;
}


void graph::addEdge(int from, int to) {
  adj[from][to] = 1;
  //adj[to][from] = 1;
}



void graph::printGraph() {
  for(int i=0; i<v; i++){
    for(int j=0; j<v; j++) {
      cout<<adj[i][j]<<"\t";
    }cout<<"\n";
  }
}

void graph::bfs(int source) {

  bool visited[v] = {false};
  int queue[v];
  int front=-1; int rear=-1;
  queue[++rear] = source; visited[source] = true;
  while(front != rear) {
    int deq = queue[++front]; cout<<deq<<"\t";
    for(int i=0; i<v; i++) {
      if(visited[i] == false && adj[deq][i]==1) {
        queue[++rear] = i;
        visited[i] = true;
      }
    }
  }
  cout<<endl;

}


void graph::dfs(int source) {
  bool visited[v] = {false};
  int stack[v];
  int top = -1;
  stack[++top] = source; visited[source] = true;
  while(top>=0) {
    int pop = stack[top--]; cout<<pop<<"\t";
      for(int i=0; i<v; i++) {
        if(visited[i] == false && adj[pop][i]==1) {
          stack[++top] = i;
          visited[i] = true;
        }
      }
  }
  cout<<endl;
}

void graph::transpose() {
  graph t(v);
  for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++) {
      t.adj[i][j] = !adj[i][j];
    }
  }
  t.printGraph();
}

void graph :: filterOdd(int source) {
  bool visited[v] = {false};
  int stack[v];
  int top = -1;
  stack[++top] = source; visited[source] = true;
  while(top>=0) {
    int pop = stack[top--]; if(pop%2!=0) cout<<pop<<"\t";
      for(int i=0; i<v; i++) {
        if(visited[i] == false && adj[pop][i]==1) {
          stack[++top] = i;
          visited[i] = true;
        }
      }
  }
  cout<<endl;
}

void graph :: filterEven(int source) {
  bool visited[v] = {false};
  int queue[v];
  int front=-1; int rear=-1;
  queue[++rear] = source; visited[source] = true;
  while(front != rear) {
    int deq = queue[++front]; if(deq%2==0) cout<<deq<<"\t";
    for(int i=0; i<v; i++) {
      if(visited[i] == false && adj[deq][i]==1) {
        queue[++rear] = i;
        visited[i] = true;
      }
    }
  }
  cout<<endl;
}

void graph :: printAllPaths(int s, int d) {

  bool visited[v] = {false};
  int path[v];
  int path_index = 0;

  printAllPathsHelper(s,d,visited,path,path_index);

}

void graph :: printAllPathsHelper(int s,int d,bool visited[],int path[],int path_index) {

  visited[s] = true;
  path[path_index] = s;
  path_index++;

  if(s == d) {
    for(int i=0; i<path_index; i++)
      cout<<path[i]<<"\t";
    cout<<"\n";
  }

  else {
    for(int i=0; i<v; i++) {
      if(adj[s][i] == 1 && visited[i]==false)
        printAllPathsHelper(i,d,visited,path,path_index);
    }
  }

  path_index--;
  visited[s] = false;
}

bool graph :: pathExists(int s,int d) {
  bool visited[v] = {false};
  int stack[v];
  int top = -1;
  stack[++top] = s; visited[s] = true;
  while(top>=0) {
    int pop = stack[top--]; if(pop == d) return true;
      for(int i=0; i<v; i++) {
        if(visited[i] == false && adj[pop][i]==1) {
          stack[++top] = i;
          visited[i] = true;
        }
      }
  }
  return false;
}

bool graph :: isConnected() {
  bool connected = true;
  for(int i=0;i<v;i++) {
    for(int j=i+1; j<v; j++) {
      connected = pathExists(i,j);
      if(!connected) {
        return false;
      }
    }
  }
  return true;
}

int main() {

  graph g(7);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(1,3);
  g.addEdge(1,4);
  g.addEdge(2,5);
  g.addEdge(3,2);
  g.addEdge(3,5);
  g.addEdge(3,6);
  g.addEdge(4,3);
  g.addEdge(4,6);
  g.addEdge(6,5);

  g.bfs(0);
  g.dfs(0);
  g.filterOdd(0);
  g.filterEven(0);
  g.printAllPaths(1,3);

}
