#include<bits/stdc++.h>

using namespace std;

class Graph{
	int val;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int s ,int v);
	void Topological();
	void TopoUtil(int v , stack<int> &Stack , bool visited[]);
	void DFS();
	void Mother();
	void DetectCycle();
};

Graph::Graph(int V){

	val = V;
	adj = new list<int>[val];
}

void Graph::addEdge(int s, int v){
	adj[s].push_back(v);
}

void Graph::TopoUtil(int v , stack<int> &Stack , bool visited[]){
	
	visited[v] = true;
	
	list<int>::iterator i;
	for(i = adj[v].begin() ; i != adj[v].end() ; i++){
		if(!visited[*i]){
			TopoUtil(*i , Stack , visited);
		}
	}
	
	Stack.push(v);
}
void Graph::Topological(){
	
	stack<int> Stack;
	bool *visited = new bool[val];
	for(int i = 0; i < val ; i++) visited[i] = false;
	
	for(int i = 0; i < val ; i++){
		
		if(visited[i] == false){
			TopoUtil(i , Stack , visited);
		}
	}
		
	cout<<"Topo. sorting";
//	cout<<Stack.top();

	while(!Stack.empty()){
		cout<<Stack.top();
		Stack.pop();
	}
}
int main(){
Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
	g.Topological();
}
