#include <bits/stdc++.h>

using namespace std;

typedef pair<long long , long long> iPair;

int main() {
	long long t;
		
	cin>>t;
	
	while(t--){
		long long  d;
		long long  n;
		cin>>n;
		
		cin>>d;
		
		vector <iPair> *cont = new vector<iPair>[d+1];
		bool visited[d+1];
		for(int v = 0; v <= d ; v++) visited[v] = false;
		long long counter = n;
		while(n--){
			long long day, no , los;
			cin>>day;
			cin>>no;
			cin>>los;
			visited[day] = true;
			cont[day].push_back({los,no});
		}
		priority_queue <iPair , vector<iPair> > pq; 
		for(long long i = 1; i <= d; i++) {
			vector<iPair>::iterator it;
//			cout<<endl<<"----------"<<endl;
			if(visited[i])
			{
				for(it = cont[i].begin() ; it != cont[i].end(); it++){
					pq.push({(*it).first , (*it).second});
				//	cout<<"YOo=>"<<(*it).first<<" "<<(*it).second<<"\n";
				}
			}

			if(!pq.empty()){
					long long f = pq.top().first;
				long long s = pq.top().second;
				s--;
				pq.pop();
				if(s != 0) {
					pq.push({f,s});
				} 
			}
		}
		int v = 0;
		while(!pq.empty()){
			 v += (pq.top().first * pq.top().second);
		//	cout<<"ans=>"<<v<<"\n";
			pq.pop();
		}
		cout<<v<<"\n";
	}
}
