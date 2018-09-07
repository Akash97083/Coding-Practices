#include<bits/stdc++.h>
using namespace std;


int midUtil(int s , int e) {
	return s + (e - s)/2;
}

int GCD(int a, int b) {	
	if(a == 0) return b;
	return GCD(b%a, a);
}

int LCM(int a , int b) {
	if(a == 0 || b == 0) return 0; 
	return (int)a*b/(int)GCD(a,b);
}

int composeSTUtil(int *st , int arr[] , int ss , int se , int si){
	
	if(ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}
	
	int mid = midUtil(ss , se);
	
	st[si] = LCM(composeSTUtil(st , arr , ss , mid , si*2 + 1) , composeSTUtil(st ,arr, mid+1 , se , si*2 +2));
}

int * composeST(int arr[] , int n){
	
	int h = (int)(ceil(log2(n)));
	
	int max = 2 * pow(2 , h) - 1;
	
	int *st = new int[max];
	
	composeSTUtil(st , arr , 0 , n-1 , 0);
	
	return st;
}

int findLCM(int *st , int l ,int r , int ss , int se , int si){
	
	if(l <= ss && r >= se) {
		return st[si];
	}
	
	if(ss > r || l > se){
		return 1;
	}
	
		int mid = midUtil(ss , se);
		
		return LCM(findLCM(st , l , r , ss, mid, si*2 + 1) , findLCM(st , l , r , mid+1 , se , si*2 + 2));
}

int main() {

	int arr[] = {1 , 2 ,3  , 4 , 5, 6 } ;
	   
	int n = sizeof(arr)/sizeof(arr[0]);
	int *st = composeST(arr , n);

	for(int i = 0; i < 15; i++) cout<<st[i]<<" -> ";
	
	cout<<endl<<findLCM(st , 1 , 5 , 0 , n-1 , 0);
}
