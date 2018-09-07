#include<bits/stdc++.h>

using namespace std;

struct Point{
	int x;
	int y;
};

int orientation(struct Point p1 , struct Point p2 , struct Point r){
	int val = ((p2.y - p1.y) * (r.x - p2.x) - (r.y - p2.y)*(p2.x - p1.x));
	
	if(val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

void converthull(struct Point points[] , int n , stack<int> &Stack){
	
	int l;
	for(int i = 0; i< n; i++){
		if(points[l].x > points[i].x) {
			l = i;
		}
	}
	
	int k = 0;
	int p = l;
//	cout<<p;
	
	do{
		Stack.push(l);
	//	cout<<l;
		k = (l+1)%n;
		for(int i = 0;i < n; i++) {
			if(orientation(points[l] , points[i] , points[k]) == 2){
				k = i;
			}		
		}
		
//		cout<<k;
		l = k;
	}while(l != p);
	
	while(!Stack.empty()){
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
	
}

int main()
{
	Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
	
	int n = sizeof(points)/sizeof(points[0]);
	
	stack<int> Stack;
	converthull(points , n , Stack);
}
