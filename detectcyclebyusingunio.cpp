#include <bits/stdc++.h>

using namespace std;



class Graph{
	
	struct set{
		int parent;
		int rank;
	};
	
	int V;
	list<int> *adj;
public:
	Graph(int _V);
	void addEdge(int s , int v);
	int find(int x , struct set *s);
	int Union(int x ,int y , struct set *s);
	bool isCyclic();	
};

Graph::Graph(int _V){
	V = _V;
	adj = new list<int>[V];
}

void Graph::addEdge(int s, int v){
	adj[s].push_back(v);
	adj[v].push_back(s);
}

int Graph::find(int x , struct set *s){
	
	if(s[x].parent != x) {
		s[x].parent = find(s[x].parent , s);
	}
	return s[x].parent;
}

int Graph::Union(int x , int y , struct set *s){
	
	int xparent = find(x,s);
	int yparent = find(y,s);
	
	if(s[xparent].rank < s[yparent].rank){
		s[xparent].parent = yparent;
	} else if(s[xparent].rank > s[yparent].rank){
		s[yparent].parent = yparent;
	}
	
	if(s[xparent].rank == s[yparent].rank){
		s[yparent].parent = xparent;
		s[xparent].rank++;
	}
}

bool Graph::isCyclic(){
	
	list<int>::iterator i;
	bool *visited = new bool[V];
	
	struct set * subset = new struct set [V];
	for(int j = 0 ; j <= V; j++){
		subset[j].parent = j;
		subset[j].rank = 0;
	}
	
	for(int j = 0; j < V; j++){		
		for(i = adj[j].begin() ; i!= adj[j].end(); i++){
			if(!visited[*i]) {
				int xroot = find(j , subset);
				int yroot = find(*i , subset);
				
				if(xroot == yroot) return true;
				else{
					Union(xroot,yroot,subset);
				} 
			}
		}	
	}
	return false;
}

int main()
{
	Graph g(3);
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);	
	(g.isCyclic())?cout<<"YES - Cycle is present in Graph\n": cout<<"Nopssss\n";
}
