#include<bits/stdc++.h>

using namespace std;

struct node
{
	int val;
	struct node *link;
};

struct node* Add(struct node * l , int n) {
	if(l == NULL){
		struct node * temp = new node;
		
		temp->val = n;
		temp->link = NULL;
		return temp;
	}
	else{
		 l->link = Add(l->link , n);
		 return l;
	}
}

struct node * Delete(struct node * l , int n , struct node* pre){
	if(l == NULL){
		return l;
	}
	else{
		while(l){
			if(l->val == n){
				pre->link = l->link;
				return pre;
			}
			else
			{
				pre = l;
				l = l->link;
			}
		}
	}
	return l;
}


int main(){
	struct node *list = NULL;
	int val , a , b , c , n;
	cin>>n;
	
	while(n--){
		
		list = Add(list , n);
	}
	Delete(list ,3 ,NULL);
	while(list){
		cout<<list->val<<" ";
		
		list = list->link;
	}
}
