#include <bits/stdc++.h>

#define INF 100000
using namespace std;

struct Point{
	int x;
	int y;
};

int orientation(struct Point p1 , struct Point p2 , struct Point r) {
	
	int ori = ((p2.y - p1.y)*(r.x - p2.x) - (r.y - p2.y)*(p2.x - p1.x) );
	
	if(ori == 0) return ori;
	
	return (ori > 0) ? 1:2;
}

bool onSegment(struct Point p1 , struct Point p2 , struct Point r) {
	
	if(r.x <= max(p1.x , p2.x) && r.x >= min(p1.x, p2.x) && r.y <= max(p1.y , p2.y) && r.y >= min(p1.y , p2.y))
		return true;
	return false;
}
bool doIntersect(struct Point p1 , struct Point p2 , struct Point q1 , struct Point q2) {
	
	int o1 , o2 , o3 , o4;
	
	o1 = orientation(p1 , p2 ,q1);
	o2 = orientation(p1 , p2 ,q2);
	o3 = orientation(q1 , q2 ,p1);
	o4 = orientation(q1 , q2 ,p2);
	
	if(o1 != o2 && o3 != o4) {
		return true;
	}
	if(o1 == 0 && onSegment(p1 , p2 , q1)) return true;
	if(o2 == 0 && onSegment(p1 , p2 , q2)) return true;
	if(o3 == 0 && onSegment(q1 , q2 , p1)) return true;
	if(o4 == 0 && onSegment(q1 , q2 , p2)) return true;
	return false;
}

bool isInside(struct Point Points[] ,int n ,struct Point p1){
	if(n < 3) return false;
	
	int i = 0;
	int next = 0;
	int count = 0;
	
	struct Point p2 = {INF ,p1.y}; 
	do{
		next = (i+1)%n;
		
		if(doIntersect(Points[i] , Points[next] , p1 , p2) ) {
			if(orientation(Points[i] , Points[next]  ,p1) == 0)
				if(onSegment(Points[i] , Points[next] ,p1))
					return true;
			count++;
		}
		i = next;	
	}while(i != 0);
	
	if(count%2 == 0) {
		return false;
	}
	return true;
}

int main(){
	
	struct Point Points[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	int n = sizeof(Points)/sizeof(Points[0]);
	
	struct Point P = {20, 20};
	
	isInside(Points , n , P) ? cout<<"YES\n": cout<<"NO\n";
}
