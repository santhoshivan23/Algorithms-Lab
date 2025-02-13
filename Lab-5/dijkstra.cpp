#include<iostream>
#define V 9
#define MAX 999999
using namespace std;

int minDistance(int dist[], bool sptSet[]) {
	int min=MAX,min_index;

	for(int v=0;v<V;v++)
		if(sptSet[v]==false && dist[v]<=min)
			min=dist[v], min_index=v;

	return min_index;
}

int printsol(int dist[])
{

	for(int i=0;i<V;i++)
		cout<<dist[i]<<"\t";
	cout<<"\n";
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];

	bool sptSet[V];

	for(int i=0;i<V;i++)
		dist[i]=MAX, sptSet[i]=false;

	dist[src]=0;

	for(int i=0;i<V;i++)
	{
		int u=minDistance(dist, sptSet);

		sptSet[u]=true;
		for(int v=0;v<V;v++)
		{if(!sptSet[v] && graph[u][v] && dist[u]!=MAX
			&& dist[u] + graph[u][v]<dist[v])
		dist[v]=dist[u]+graph[u][v];
		}
	}

	printsol(dist);
}

int main()
{
	    // int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
      //                   { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
      //                   { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
      //                   { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      //                   { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      //                   { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
      //                   { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
      //                   { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
      //                   { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

			int v;
			cout<<"Input no. of vertices\n";
			cin>>v;
			cout<<

    dijkstra(graph, 0);

    return 0;
}
