#include<bits/stdc++.h>

#define INF -999
using namespace std;

class Adjlist{
	int val;
	int weight;
public:
	Adjlist(int v , int w) {val = v; weight = w;}
	int getV(){ return val;}
	int getW(){ return weight;}
};

class Graph{
	int V;
	list<Adjlist> *adj;
public:
	Graph(int _V);
	void addEdge(int s , int v , int w);
	void TopologicalUtil(int v, stack<int> &Stack , bool visited[]);
	void findLongestPath(int s);
};

Graph::Graph(int _V){
	V = _V;
	adj = new list<Adjlist>[V]; 
}

void Graph::addEdge(int s ,int v , int w)
{
	Adjlist node(v , w);
	adj[s].push_back(node);
}

void Graph::TopologicalUtil(int v ,stack<int> &Stack , bool visited[]) {
	
	visited[v] = true;
	
	list<Adjlist>::iterator i;
	
	for(i = adj[v].begin(); i != adj[v].end() ; i++){
		Adjlist node = *i;
		if(!visited[node.getV()]) TopologicalUtil(node.getV() , Stack , visited);
	}
	
	Stack.push(v);	
}

void Graph::findLongestPath(int s){
	
	stack<int> Stack;
	int dis[V];
	bool *visited = new bool[V];
	
	for(int i = 0; i< V ;i++){
		visited[i] = false;
		dis[i] = INF;
	}
	
	for(int i = 0; i < V ; i++)
		TopologicalUtil(i ,Stack, visited);
		
		dis[s] = 0;
	while(!Stack.empty()){
		int v = Stack.top();
		Stack.pop();
		
		list<Adjlist>::iterator i;
		
		if(dis[v] != INF){
			for(i = adj[v].begin() ; i != adj[v].end() ; i++) {
				Adjlist node = *i;
				if(dis[i->getV()] < dis[v]+i->getW()) {
					dis[i->getV()] = dis[v]+i->getW();
				}
			}
		}
	}
		for(int i = 0 ; i < V ; i++){
			(dis[i] == INF)? cout<<"INF"<<" " : cout<<dis[i]<<" ";
		}
}
int main()
{
	int n;
	cin>>n;
	Graph g(n);	
	
	  g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    g.findLongestPath(s);
}
