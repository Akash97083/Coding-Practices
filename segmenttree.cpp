#include <bits/stdc++.h>

using namespace std;

int midUtil(int s, int e){
	return (s + ((e-s)/2));
}
int ConstructSTUtil(int *st , int arr[] , int ss , int se , int si){
	
	if(ss == se){
		st[si] = arr[ss];
		return arr[ss];
	}
	
	int mid = midUtil(ss , se);
	st[si] = ConstructSTUtil(st , arr , ss , mid , si*2 +1 ) + ConstructSTUtil(st , arr , mid+1 , se , si*2 + 2);
	
	return st[si];
}

int * ConstructST(int arr[] ,int n ) {
	
	int h = (int)(ceil(log2(n)));
	
	int max = 2*pow(2,h) - 1;
	
//	cout<<h<<" "<<max<<"\n";
	int *st = new int[max];
	
	ConstructSTUtil(st , arr , 0 , n-1 , 0);
	return st;
}

int findSumUtil(int *st , int ss ,int se , int s , int e , int si){
	

	if(ss >= s && se <= e) {
		cout<<"val => "<<si<<" "<<st[si]<<"\n";
		return st[si];
	}
	
	if(ss > e || se < s){
		return 0;
	}
	
//	cout<<sum<<" - ";
	int mid = midUtil(ss , se);
	return findSumUtil(st , ss , mid , s , e , si*2 +1) + findSumUtil(st , mid+1 , se , s , e , si*2 +2);
	
}

int findSum(int *st , int l , int r , int n){
	
	if(l < 0 || r > n || r < l) {
		cout<<"Invalid Input\n";
		cout<<n<<"\n";
		cout<<r<<" "<<l<<"\n";
		return -1;
	}
	return findSumUtil(st , 0 , n-1 , l , r , 0);
}
int main()
{
	 int arr[] = {1, 3, 5, 7, 9, 11};
	
	int n =  sizeof(arr)/sizeof(arr[0]);
	int *st;
	
	st = ConstructST(arr , n);
	int i = 0;
	
	cout<<findSum(st , 3, 3 , n)<<"\n";
	
	while(st[i]){
		cout<<st[i]<<" ";
		i++;
	}
	
}
