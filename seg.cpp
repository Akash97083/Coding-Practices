#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;
int main(){
	
	unordered_map<char , int> seg;
	
	string s;
	
	cin>>s;
	
	int i = 0;
	
	while(s[i]){
		if(seg.find(s[i]) == seg.end()){
			seg[s[i]] = 1;
		//	cout<<"*\n";
		}
		else {
			seg[s[i]]++;
		//	cout<<"-\n";
		}
			
		i++;
	}
	unordered_map<char , int>::iterator itr;
	
	for(itr = seg.begin() ; itr != seg.end() ; itr++){
		int j = 0;
		int v = itr->second;

		while(j < v){
			cout<<itr->first;
			j++;
		}
	//	cout<<"\n";
	}
	
}
