#include <bits/stdc++.h>

using namespace std;

int midUtil(int s , int e) {
	return s + (e-s)/2;
}

int composeSTUtil(int *s, int ss , int se , int arr[] ,int si){
	
	if(se == ss){
		s[si] = arr[ss];
		return arr[ss];
	}
	
	int mid = midUtil(ss, se);
	
	s[si] = composeSTUtil(s , ss , mid , arr , si*2 +1) + composeSTUtil(s , mid+1 , se , arr , si*2 +2);
	return s[si];
}

int * composeST(int arr[] , int n) {
	
	int h = (int)(ceil(log2(n) ));
	
	int max = 2 * (int)pow(2,h) - 1;
	
//	cout<<h<<endl;
//	cout<<max<<endl;
	int *s = new int[max];
	
	composeSTUtil(s , 0 , n-1, arr , 0);
	
	return s;
}

void UpdateSTUtil(int *st , int ss , int se , int i , int val , int si) {
	
	if(i < ss || i > se){
		return;
	}
	st[si] += val;
	
	if(se != ss) {
		int mid = midUtil(ss , se);
		UpdateSTUtil(st , ss , mid ,  i , val ,  si*2 + 1);
		UpdateSTUtil(st , mid+1 ,  se , i , val , si*2 + 2);
	}
}

void UpdateST(int *st , int arr[] , int n , int i ,int val){
	
	int diff = val - arr[i];
	arr[i] = diff;
	UpdateSTUtil(st  , 0 ,n-1, i , diff , 0);
}

int SumUtil(int *st , int l , int r , int ss , int se , int si){
	
	if(ss >= l && se <= r ) {
		return st[si];
	}
	
	if(l > se || r < ss ) return 0;
	
	int mid = midUtil(ss , se);
	
	return SumUtil(st ,l , r , ss , mid ,si*2 +1) + SumUtil(st , l , r , mid+1 , se , si*2 +2);
}

void Sum(int *st , int l , int r , int n){
	
	int sum = SumUtil(st , l , r , 0 , n-1, 0);
	cout<<sum;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	

	int n = sizeof(arr)/sizeof(arr[0]);
	
	int *st;
	
	st = composeST(arr , n);
//	UpdateST(st , arr , n , 5 , 1);
	Sum(st , 5 , 5  , n);
}
