#include<bits/stdc++.h>
using namespace std;


int main() {

	list<int> l;
	
	int a = 0;
	while(a !=1){
		cin>>a;
		l.push_back(a);
		
		list<int>::iterator it;
			cout<<"\n";
		for(it = l.begin(); it!= l.end() ; it++) {
			cout<<*it<<"->";
		}
	
	}
}
