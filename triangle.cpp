#include<bits/stdc++.h>

using namespace std;

struct point{
	int x;
	int y;
};

int orientation(struct point p1 , struct point p2 , struct point r){
	
	int val =  (p2.y - p1.y )*(r.x -p2.x) - (r.y-p2.y) * (p2.x - p1.x);
	
	if(val == 0) return 0;
	
	if(val > 0) return 1;
	else return 2;
}

int onsegment(struct point p1 , struct point p2 , struct point r){
	
	if(r.x >= min(p1.x , p2.x) && r.x <= max(p1.x , p2.x) && r.y >= min(p1.y , p2.y) && r.y <= max(p1.y , p2.y)) {
		return 1;
	}
	return 0;
}

int main(){
	int t;
	int x , y;
	struct point t1 ,t2 , t3 , p;
//	cin>>t;
	
	cin>>t1.x>>t1.y;
	cin>>t2.x>>t2.y;
	cin>>t3.x>>t3.y;
	
	if(1){
		cin>>p.x;
		cin>>p.y;
		
		int o1 = orientation(t1 , t2 , p);
		int o2 = orientation(t2 , t3 , p);
		int o3 = orientation(t3 , t1 , p);
		
		if(o1 == o2 && o2 == o3) {
			cout<<"Inside\n";
		}			
		
		else if(o1 == 0 && onsegment(t1 , t2 ,p)){
			cout<<"Inside\n";
		}
		else if(o2 == 0 && onsegment(t2 , t3 ,p)){
			cout<<"Inside\n";
		}
		else if(o3 == 0 && onsegment(t3 , t1 ,p)){
			cout<<"Inside\n";
		}
		else cout<<"Not Inside\n";
	}
	
}
