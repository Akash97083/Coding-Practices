// C++ implementation of search and insert operations
// on Trie by Sunny Singh Yadav

#include<bits/stdc++.h>

using namespace std;

bool found = false;

// trie node
struct Tries{
	map<char ,struct Tries *> m;
	
	 // leaf is true if the node represents
    // end of a word
	bool leaf;
	
	//initialize leaf to false
	Tries(){ leaf = false; }
};

// If not present, inserts S into trie
// If the S is prefix of trie node, just marks leaf node
void Insert(struct Tries *top , string S){
	
	struct Tries *temp ;
	for(int i = 0 ; i < S.length(); i++){
		if(top->m.find(S[i]) == top->m.end()){
			top->m[S[i]] = new Tries;
		}
		top = top->m[S[i]];
	}
	// mark last node as leaf
	top->leaf = true;
	
}

// display all the value in Trie
void display(struct Tries *root){
	
		map<char , struct Tries *>::iterator itr;
		
		if(root->leaf == true) cout<<"\n";
		
		for(itr = root->m.begin(); itr != root->m.end() ; itr++){
			cout<<(itr->first);		
			display(root->m[itr->first]);
		}
}

// Search for String in Tire
void Search(struct Tries *root , string S) {
	
	map<char , struct Tries *>::iterator itr;
	
	bool flag = false;
	int i;
	for(i = 0 ; i < S.length(); i++){
		if(root->m.find(S[i]) != root->m.end()){
			root = root->m[ S[i] ];
		}
		else break;
	}
	cout<<S;
	if(root->leaf) (i == S.length()) ? cout<<" is Present in trie" : cout<<" is not Present in trie";
	else cout<<" is not Present in trie";
		
}

// Driver
int main(){
	struct Tries *root = new Tries;	
	string str ;
	
	// Input String (values are case sensitive)
	str = "ABCD";
	Insert(root ,str);

	str = "XYZ";
	Insert(root ,str);
	
	str = "LMNOP";
	Insert(root ,str);
	
	// display all the value in Trie
	display(root);
	
	str = "XY";
	found = false;
	// Search for  str
	Search(root ,str);
	
	return 0;
}
