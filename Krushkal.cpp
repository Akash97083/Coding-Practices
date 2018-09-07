#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

class Graph{
	int V;
	int E;
	vector < pair<int, iPair> > edge;
	
public:
	Graph(int V , int E){
		this->V = V;
		this->E = E;
	}
		
	void addEdge(int s , int v , int w){
		edge.push_back( {w ,{s, v} } );
	}
	
	int Kruskal();
};

struct Subset{
	int *Parent;
	int *Rank;
	int n;
	Subset(int V){
		Parent = new int[V+1];
		Rank = new int[V+1];
		n = V;
		
		for(int i = 0; i <= n; i++){
			Parent[i] = i;
			Rank[i] = 0;
		}
	}
	
	int find(int x){
		if(Parent[x] != x) {
			Parent[x] = find(Parent[x]);
		}
		return Parent[x];
	}
	
	void Union(int x , int y){
	//	cout<<x<<"-"<<y<<"\t";
		int xp = find(x);
		int yp = find(y);
	//	cout<<xp<<"-"<<yp<<endl;
		if(Rank[xp] > Rank[yp]) {
			Parent[yp] = xp;
		}
		
		else{
			Parent[xp] = yp;
		}
		
		if(Rank[xp] == Rank[yp]) {
			Rank[yp]++;
		}
	}
	
};

int Graph::Kruskal(){
	
	int mst_w = 0;
	
	sort(edge.begin() , edge.end());
	
	vector< pair<int , iPair> >::iterator i;
	
	Subset st(V);
	
	for(i = edge.begin() ; i != edge.end() ; i++){
		
		int w = i->first;
		//cout<<w;
		int s =  i->second.first;
		int v =  i->second.second;
		
//		cout<<"\n*"<<s<<"-";
		int x = st.find(s);
//		cout<<x<<" \t *y "<<v<<" - ";
		int y = st.find(v);
//		cout<<y<<endl;
	//	if(x == y) cout<<"Equal"<<endl;

		if(x != y) 
		{
	 		cout<<s<<"-"<<v<<endl;
			mst_w += w;	
			st.Union(x , y);
		}
	}
	cout<<mst_w;
	return mst_w;
}

int main(){
	
	int V = 9, E = 14;
    Graph g(V, E);
 
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

	g.Kruskal();
	
	return 0;
}
