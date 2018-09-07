#include <bits/stdc++.h>

using namespace std;

class Graph{
	int val;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int s , int v);
	void DFS(int v);
	void DFSUtil(int v , bool visited[]);
};

Graph::Graph(int V){
	val = V;
	adj = new list<int>[val];
}

void Graph::addEdge(int s , int v){
	adj[s].push_back(v);
}

void Graph::DFSUtil(int v , bool visited[]){
	
	cout<<v<<" ";
	visited[v] = true;
	
	list<int>:: iterator i;
	
	for(i = adj[v].begin() ; i != adj[v].end() ; i++){
		if(!visited[*i]) {
			DFSUtil(*i , visited);
		}
	}
}
void Graph::DFS(int v){
	bool *visited = new bool[val];
	
	for(int i = 0 ;i < val ; i++){
		visited[i] = false;
	}
	
	DFSUtil(v, visited);
}
int main()
{
	int n = 4, a , b;
	
	Graph g(n);
	n = 6;
	while(n--){
		cin>>a;
		cin>>b;
		g.addEdge(a , b);
	}
	g.DFS(1);
	
}
