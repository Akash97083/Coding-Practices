#include<bits/stdc++.h>

using namespace std;

class Graph{
	int val;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v ,int s);
	bool isCycle();
	bool checkCycle(int v, bool visited[] , bool bridge[]);
};

Graph::Graph(int V){
	val = V;
	adj = new list<int>[val];
}

void Graph::addEdge(int s ,int v){
	adj[s].push_back(v);
}

bool Graph::checkCycle(int v, bool visited[] , bool bridge[]){
	
	visited[v] = true;
	bridge[v] =true;
	
	list<int>::iterator i;
	
	for(i = adj[v].begin(); i != adj[v].end(); i++){
		if(bridge[*i]) return true;
		if(!visited[*i] && checkCycle(*i, visited , bridge))
			return true;
		
	}
	bridge[v] = false; 
	
	return false;
}

bool Graph::isCycle(){
	bool *visited = new bool[val];
	bool *bridge = new bool[val];
	
	
	for(int i = 0 ; i < val; i++){
		visited[i] = false;
			bridge[i] = false;
	}
	for(int i = 0; i < val ;i++)	
		if(checkCycle(i , visited , bridge)) {
			return true;
		}
		return false;
}

int main()
{
	int n , a ,b ;
	cin>>n;
	Graph g(n);
	
	cin>>n;
	
	for(int i = 0; i< n; i++){
		cin>>a ;
		cin>>b;
		g.addEdge(a ,b);
	}
	if(g.isCycle()){
		cout<<"true";
	}
	else cout<<"false";
}
