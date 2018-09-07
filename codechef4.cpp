    #include<bits/stdc++.h>
     
    using namespace std;
     
    class Adjlist{
    	long long val;
    	long long weight;
    public:
    	
    	Adjlist(long long v, long long w) {
    		val = v; weight = w;
    	}
    	long long getV() {
    		return val;
    	}
    	long long getW(){
    		return weight;
    	}
    };
     
     class Graph2{
    	
    public:
    	long long v_;
    	list<long long> *ad;
    	Graph2() {
    		v_ = 99999;
    		ad = new list<long long>[v_];
    	}
    	void AddEdge(long long s , long long v){
    		ad[s].push_back(v);
		}
    }shc;
    
    
    class Graph{
    	long long V;
    	list<Adjlist> *adj;
    	long long exp;
    public:
    	Graph(long long _V);
    	void addEdge(long long s ,long long v , long long w);
    	void Sove(long long a , long long b , long long k);
    	bool SolveUtil(bool visited[] ,long long a , long long b , long long k , stack<long long> &Stack , long long W, stack<long long> &StackW );	
    };
     
    Graph::Graph(long long _V){
    	V = _V;
    	adj = new list<Adjlist>[V];
    }
     
    void Graph::addEdge(long long s , long long v, long long w){
    	Adjlist node(v, w);
    	adj[s].push_back(node);
    	
    	Adjlist node1(s , w);
    	adj[v].push_back(node1);
    }
     
    bool Graph::SolveUtil(bool visited[] ,long long a , long long b , long long k , stack<long long> &Stack , long long W , stack<long long> &StackW ){
     
    FACE:
    	list<Adjlist>::iterator i;
    	visited[a] = true;
     
    		Stack.push(a);
    		StackW.push(W);
        int  s = a;
      //  cout<<a<<" - ";	
        if(a == b){
        	while(!StackW.empty()){
					shc.AddEdge(a+b, StackW.top());				
    	     		StackW.pop();
    	     		Stack.pop();
    		}
        /*		while(val == 0 && !StackW.empty()){
    				if(StackW.top() <= k)
    				val = StackW.top();
    				StackW.pop();
    				Stack.pop();
    			}
        	while(!StackW.empty()){
        		if(StackW.top() <= k)
    		    	val = val ^ StackW.top();	
    	     	StackW.pop();
    	     	Stack.pop();
    		}
    		cout<<val<<"\n";
    		while(!Stack.empty()){
    			Stack.pop();
    		}
    		while(!StackW.empty()){
    			StackW.pop();
    		} */
    		return true;
    	}
    	int count = 0;
    		while(!Stack.empty()){
    			
    			for(i = adj[s].begin() ; i != adj[s].end() ; i++){
    				Adjlist node = *i;
    				if(!visited[node.getV()]){
    					count++;
    					a = node.getV();
    					W = node.getW();
    					goto FACE;
    				//	SolveUtil(visited , node.getV() , b , k , Stack , node.getW() , StackW);
    				//	return true;
    				}
    	     	}
    	     	if(count == 0){
    	     		Stack.pop();
    	     		if(!Stack.empty())
    	     			s = Stack.top();
    	     		StackW.pop();
    			 }
    		}
     
    	
    }
    void Graph::Sove(long long a , long long b , long long k){
    	
    		
    	bool *visited = new bool[V+1];
    //	cout<<"V "<<V<<"\n";
    	for(long long i = 0 ; i <= V ; i++) {
    		visited[i] = false;
    	//	cout<<i<<" \n";
    	}
    	
    	stack<long long>Stack;
    	stack<long long>StackW;
    /*	while(!Stack.empty()){
    		Stack.pop();
    	}
    	while(!StackW.empty()){
    		StackW.pop();
    	}*/
    	SolveUtil(visited , a, b ,k ,Stack , 0 ,StackW);  
     
    }
     
    int main()
    {
     
    	long long n , m , a , b , c , w , x, y ,k , t;
    	cin>>t;
    	
    	while(t--){
    		cin>>n;
    		Graph g(n+1);
    		long long i = n;i--;
    		while(i--){
    			cin>>a;
    			cin>>b;
    			cin>>c;
    			g.addEdge(a , b, c);
    		}
    		
    		for(i = 1; i <= n ; i++) {
    			for(int j = i+1; j <= n;j++){
    				g.Sove(i , j , k);
				}
			}
    	
    /*		for(i = 1; i <= n ; i++) {
    			for(int j = i+1; j <= n;j++){
    				int s = i+j;
    					list<long long>::iterator ll;
    					cout<<i+j<<"->"<<" "<<" : ";
    					for(ll = shc.ad[s].begin() ;ll != shc.ad[s].end() ; ll++){
    						cout<<*ll<<" ";
						} cout<<"\n";
				}
			} */
    		cin>>m;
    		
    			while(m--){
    				cin>>a;
    				cin>>b;
    				cin>>k;
    				int s = a+b;
    				int val = 0;
    				list<long long>::iterator i;
    				for(i = shc.ad[s].begin() ; i != shc.ad[s].end() ; i++){
    					cout<<*i;
					}
	    			cout<<val<<"\n";
	    		}
    	}
    	return 0;
    } 
