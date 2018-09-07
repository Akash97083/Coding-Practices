#include <bits/stdc++.h>

using namespace std;

bool solve(vector< vector<int> > v , int n,  int m , string a , string b , string c) {
	
	 n = b.length();
	 m = a.length();
 int z = c.length();	
	
	//cout<<n<<" "<<m<<" "<<z<<"\n\n\n";
		
	if(n+m != z) return false;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			v[i][j] = false;
			if(i == 0 && j == 0) v[i][j] = true;
			else if(i == 0 && a[j-1] == c[j-1]) v[i][j] = v[i][j-1];
			
			else if(j == 0 && b[i-1] == c[i-1]) v[i][j] = v[i-1][j];
			else if(a[j-1] == c[i+j-1] && v[i][j-1] == true) v[i][j] = true;
			else if(b[i-1] == c[i+j-1] && v[i-1][j] == true) v[i][j] = true; 
			
	//		cout<<v[i][j]<<"\t";
		}
	//	cout<<"\n\n";
	}
	return v[n][m];
}

int main()
{
	
	int t, n , m;
	
	cin>>t;
	
	while(t--){
		vector< vector<int> > v(10000 , vector<int>(10000));
		string a ,b , c;
		
		cin>>a>>b>>c;
	//	getline(cin, a);
	//	getline(cin , a);
	//	getline(cin , b);
	//	getline(cin , c);
		(solve(v , n , m , a , b , c)) ? cout<<"True\n" : cout<<"False\n";
	}
	return 0;
}
