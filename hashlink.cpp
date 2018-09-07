#include<bits/stdc++.h>

using namespace std;

struct node{
	float pre_price;
	float change;
	
	struct node *next;
};

struct hash{
	map<string , struct node* > mp;
};


struct node * InsertUtil( struct node *top , float pre_price , float change){
	
	if(!top){
		top = new node;
		top->change = change;
		top->pre_price = pre_price;
		top->next = NULL;
		return top;
	}
//	cout<<"1";
	top->next = InsertUtil(top->next , pre_price , change);
	return top;
}

struct hash insert(struct hash top , string company_name , float pre_price , float change){
	
	if(top.mp.find(company_name) == top.mp.end()){
		top.mp[company_name] = NULL;
		top.mp[company_name] = InsertUtil(top.mp[company_name] , pre_price , change);
 	}
	else
		top.mp[company_name] = InsertUtil(top.mp[company_name] , pre_price , change);
	return top;
}

int main(){

	struct hash top ;
	
	top = insert(top , "Morgon" , 5.55 , 0.03);
	insert(top , "Morgon" , 6.55 , 0.03);
	insert(top , "Morgon" , 7.55 , 0.03);
	top = insert(top , "Google" , 5.55 , 0.03);
	insert(top , "Google" , 6.55 , 0.03);
	insert(top , "Google" , 7.55 , 0.03);
	top = insert(top , "Yahoo" , 5.55 , 0.03);
	insert(top , "Yahoo" , 6.55 , 0.03);
	insert(top , "Yahoo" , 7.55 , 0.03);
	top = insert(top , "Facebook" , 5.55 , 0.03);
	insert(top , "Facebook" , 6.55 , 0.03);
	insert(top , "Facebook" , 7.55 , 0.03);	
	
	map<string , struct node*>::iterator itr;
	
	for(itr = top.mp.begin() ; itr != top.mp.end() ; itr++){
		struct node *t = itr->second;
		cout<<itr->first<<" ";
		while(t){
			cout<<t->pre_price<<" ";
			t = t->next;
		}cout<<"\n";
		
	}
	
}
