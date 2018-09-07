#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int midUtil(int s , int e){
	
	return s + ((e-s)/2);
}

int  ConstructSTUtil(int *st , int arr[] , int ss , int se , int ci ) {
	
	if(ss == se){
		st[ci] = arr[ss];
		return arr[ss];
	}
	
	int mid = midUtil(ss , se);
	
	st[ci] = ConstructSTUtil(st , arr , ss , mid , ci*2 + 1) + ConstructSTUtil(st , arr , mid+1, se , ci*2 + 2);
	
	return st[ci];
}


int * ConstructST(int arr[] ,int n ) {
	
	int h = (int)(ceil(log2(n)));
	
	int max = 2*pow(2,h) - 1;
	
//	cout<<h<<" "<<max<<"\n";
	int *st = new int[max];
	
	ConstructSTUtil(st , arr , 0 , n-1 , 0);
	return st;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int *st ;
	
	st = ConstructST(arr , n);
	
	int i = 0;
	while(st[i]){
		cout<<st[i]<<" ";
		i++;
	} 
	
}
