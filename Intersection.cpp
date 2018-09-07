#include<bits/stdc++.h>

using namespace std;

struct Point{
	int x;
	int y;
};

int orientation(struct Point p1 ,struct Point p2 , struct Point r) {
	
	int val = (((p2.y - p1.y) * (r.x - p2.x))	- ((r.y - p2.y)*(p2.x - p1.x)));
	 if (val == 0) return 0;  
 
    return (val > 0)? 1: 2;
}

bool onsegment(struct Point p1 , struct Point p2 , struct Point r) {
	
	if(r.x <= max(p1.x , p2.x) && r.x >= min(p1.x , p2.x) && r.y <= max (p1.y , p2.y) && r.y >= min(p1.y , p2.y)){
		return true;
	}
	else false;
}

bool Intersection(struct Point p1 , struct Point p2 , struct Point q1 , struct Point q2){
	
	int o1 , o2 , o3 , o4;
	
	o1 = orientation(p1 , p2 , q1);
	o2 = orientation(p1 , p2 , q2);
	
	o3 = orientation(q1 , q2 , p1);
	o4 = orientation(q1 , q2 , p2);
	
	if(o1 != o2 && o3 != o4){
		return true;
	}
	
	if(o1 == 0 && onsegment(p1 , p2 , q1)) return true;
	if(o2 == 0 && onsegment(p1 , p2 , q2)) return true;
	if(o3 == 0 && onsegment(q1 , q2 , p1)) return true;
	if(o4 == 0 && onsegment(q1 , q2 , p2)) return true;
	
}

int main()
{
	struct Point p1 = { 1, 1} , q1 = {10 , 1};
	struct Point p2 = { 1, 2} , q2 = {10 , 2};
	
	Intersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
	p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    
     Intersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
 
    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    Intersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
}
