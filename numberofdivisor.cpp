#include <bits/stdc++.h>

#define MAX 1000005

#define INF 99999999
using namespace std;

long long *sp = new long long [MAX];

void sprime(){
	for(long long l = 0 ;l < MAX ; l++) sp[l] = INF;
//	sp[1] = 0;
	
	for(long long l = 2; l < MAX ; l++) {
		
		if(sp[l] == INF){
			sp[l] = l;
			for(long long i = l*l; i < MAX ; i += l){
				if(sp[i] > l) sp[i] = l;
				
			}
		}
	}
}

void divisor(long long dv[]){
	
	for(long long i = 1 ; i < MAX ; i++){
		
		int p = sp[i];
		int n = i;
		int  k = 0;
		dv[i] = 1;
	//	cout<<dv[i]<<"\n";
		while(n > 1){
			n = n/p;
			k++;
			if(p != sp[n]){
				dv[i] *= (k+1);
	//			cout<<dv[i]<<"\n";
				k = 0;
			}
			p = sp[n];		
		}
	}
}

long long midUtil(long long s , long long e) {
	return s + (e-s)/2;
}

long long constructSTUtil(long long *st , long long arr[] , long long ss , long long se , long long si ){
	
	if(ss == se){
	//	cout<<si<<" "<<se<<"\n";
		st[si] = arr[ss];
		return arr[ss]; 
	}
	
	long long mid = midUtil(ss , se);
	
	st[si] = max( constructSTUtil(st , arr ,ss , mid , si*2+1 ) , constructSTUtil(st , arr ,mid+1 , se , si*2 + 2) );
	//cout<<si<<" "<<st[si];
//	return st[si];
}

long long * constructST(long long arr[] , long long n){
	
	long long h = (long long)(ceil(log2(n)));
	long long m = 2*pow(2 , h) - 1;
//	cout<<m<<"\n";
	long long *st = new long long[m];
	
	constructSTUtil(st , arr , 0 , n-1, 0);
//	for(long long i= 0; i < 100 ; i++) cout<<i<<" "<<st[i]<<"\n";
	return st;
}

long long inRange(long long * st , long long s , long e , long long ss , long long se , long long si)
{
	if(s <= ss && se <= e) {
	//	cout<<si<<" ";
		return st[si];
	}
	
	if(ss > e || se < s) return 0;
	
	long long mid = midUtil(ss , se);
	
	return max( inRange(st , s  , e , ss , mid , si*2 + 1) , inRange(st , s , e , mid+1 , se , si*2 + 2) );
}

int main()
{
	long long *dv = new long long [MAX];
	
	sprime();
	
	divisor(dv);

	long long *st = constructST(dv , MAX);

		cout << "Maximum divisors that a number has "<< " in [1, 100] are "
         << inRange(st, 1, 100, 0, MAX-1, 0) << endl;
}
