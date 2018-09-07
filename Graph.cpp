#include<bits/stdc++.h>
#include<list>

using namespace std;

class Graph{
	int val;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v , int s);
};

Graph::Graph(int V){
	val = V;
	adj = new list <int>[val];
}

void Graph::addEdge(int v , int s){
	adj[s].push_back(v);
}
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(2,1);
}
