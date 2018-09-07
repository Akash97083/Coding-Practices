#include <bits/stdc++.h>

using namespace std;

struct tree{
	int val;
	struct tree *left , *right;
};

struct tree * insert(int a , struct tree *top){
	
	if(top == NULL){
		top = new tree;
		top->val = a;
		top->right = top->left = NULL;
//		cout<<top->val;
		return top;
	}
	
	else if(top->val < a) top->right = insert(a , top->right);
	else top->left = insert(a , top->left);	
//	return top;
}

void preorder(struct tree* top){
	if(top)
		cout<<top->val;
	if(top->left)
		preorder(top->left);
	if(top->right)	
		preorder(top->right);
}

int main()
{
	struct tree * top = NULL;
	
	int a = 1;
	
	while(a != 0){
		cin>>a;
		top = insert(a , top);
	}
	
	preorder(top);
}
