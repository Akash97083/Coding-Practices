#include<bits/stdc++.h>

using namespace std;

class Graph{
	int val;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int s ,int v);
	void BFS(int v);
	
};

Graph::Graph(int v){
	val = v;
	adj = new list<int>[val];
}

void Graph::addEdge(int s , int v){
	adj[s].push_back(v);
}

void Graph::BFS(int v){
	bool *visited = new bool[val];
	
	for(int i = 0; i < val ; i++) visited[i] = false;
	
	list<int>::iterator i;
	
	list<int> queue;
	
	queue.push_back(v);
	
	while(!queue.empty()){
		int s = queue.front();
		cout<<s<<" ";
		visited[s]= true;
		queue.pop_front();
		
		for(i = adj[s].begin() ; i != adj[s].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	int n , a , b , vertex;
	
	cin>>vertex;
	
	Graph g(vertex);
	
	cin>>n;
	
	while(n--){
		cin>>a;
		cin>>b;
		g.addEdge(a,b);
	}
	g.BFS(2);
}
