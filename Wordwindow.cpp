#include <bits/stdc++.h>
#include<tr1/unordered_map>
#define INF 99999999

using namespace std;
using namespace::tr1;

typedef pair<int , int> iPair;

int findWindow(vector <string> St , vector<string> Tt) {
	
	string S = St.at(0);

	string T = Tt.at(0);
	
	int total = 0;

	unordered_map <char , int> count;
	 
	for(int i = 0 ; i < T.length(); i++){
	//	cout<<T[i]<<"\n";
	//	cout<<S[i]<<"--------"<<"\n";
		if(count.find(T[i]) == count.end()) {
			count[T[i]] = 1;
	//		cout<<T[i]<<" "<<count[T[i]]<<"\n";
		}
		else {
		
			count[T[i]]++;
		}
	}
	
	int head;
	int lenght = -1;
	for(int i = 0 , head = 0 ; i < S.length() ; i++){
		
		if(count.find(S[i]) == count.end()) {
			
			continue;
		}
		count[S[i]]--;
		if(count[S[i]] >= 0) {
			total++;
		}
		
		if(total == T.size()) {
		//		cout<<S[i]<<" *"<<count[S[i]]<<"\n";
			while(count.find(S[head]) == count.end() || count[S[head]] < 0) {
				if(count.find(S[head]) != count.end()) {
		//			cout<<S[head]<<" -- "<<count[S[head]]<<" "<<"\n";
					count[S[head]]++;
						
				}
				head++;
			}
			
			if(lenght > i - head + 1 || lenght == -1){
				lenght = i-head + 1;
		//		cout<<"----"<<lenght<<"\n";
			}
		}
		
	}	return lenght;
}

int main(){

	vector <string> S;
	
	vector <string> T;
	
	S.push_back("AHDEBCFGAAAAABIC");
	T.push_back("ABC");	
	
	cout<<findWindow(S , T);
}
