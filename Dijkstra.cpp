#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair <int , int> iPair;

class Graph{
	int V;
	list<iPair> *adj;
public:
	Graph(int V);
	void addEdge(int s , int v , int w);
	void Dijkstra(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int s , int v , int w){
	adj[s].push_back({v,w});
	adj[v].push_back({s,w});
}

void Graph::Dijkstra(int s){
	
	priority_queue<iPair , vector<iPair> , greater<iPair> > pq;
	
	pq.push({0 , s});
	
	vector <int> dis(V , INF);
	
	dis[s] = 0;
	

	
	while(!pq.empty()){
		
			int u = pq.top().second;
	
		pq.pop();
		
		list<pair<int , int> >::iterator i;
		for(i = adj[u].begin() ; i != adj[u].end() ; i++){
		
			int v = (*i).first;
			int w = (*i).second;
			
		//	cout<<v<<" ";
				
			if(dis[v]  > dis[u] + w){
			
				dis[v] = dis[u]+w;
				pq.push({dis[v], v});
			}
	//		cout<<v<<endl;
		}
		
	}
	
	for(int i = 0 ; i < V; i++) {
		cout<<i<<" "<<dis[i] <<endl;
	}
}

int main()
{
		int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.Dijkstra(0);	
}
