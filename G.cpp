#include<bits/stdc++.h>

int midUtil(int s , int e) {
	return s + (e - s)/2;
}

int constructSTUtil(int *st , int arr[] , int ss , int se , int si) {
	
	if(ss == se){
		st[si] = arr[ss];
		return st[ss];
	}
	
	int mid = midUtil(ss , se);
	
	st[i] = GCD( constructSTUtil(st , arr , ss , mid , si*2 + 1) , constructSTUtil(st , arr , mid+1 , se , si*2 +2) );
}

int* constructST(int arr[] , int n) {
	
	int h = (int)ceil(log2(n));
	
	int m = 2 * pow(2 , h) -1;
	
	int * st = new int[m];
	
	constructSTUtil(st , arr , 0, n-1 ,0);
	
	return st;
}

int findSubset(int *st , int ss , int se) {
			
}

int main(){
	
	int arr[] = {1 , 2 , 3 , 4 , 5 , 6};
	
	int n = (sizeof(arr)/sizeof(arr[0]));
	
	int *st = constructST(arr , n);
	
	findSubset(st , ss ,n-1)	
}
