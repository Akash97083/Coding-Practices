#include <bits/stdc++.h>

using namespace std;

void findPermutationUtil(string str , int n, int orgl , map<char , int> plot ,   int i , string S , int index){
	
	if(i != -1){
		plot[str[i]]--;
	}
	if(index == orgl) {
		for(int l = 0; l <= n ; l++){
			if(plot[str[l]] > 0){
				S[index] = str[l];
				break;
			}
		}
		cout<<S<<"\n";
		return;
	}
	
	for(int l = 0; l <= n ; l++){
		if(plot[str[l]] > 0){
			S[index] = str[l];
			findPermutationUtil(str , str.length()-1, orgl , plot , l , S, index+1);
		}
	}
}

void findPermutation(string str, int n , map<char , int> plot){
	
	char S1[n]; 
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(plot.find(str[i]) == plot.end()) 
		{
			plot[str[i]] = 1;
			S1[j] = str[i];
			j++;
		}
		else
			plot[str[i]]++;
	}
	
	string S = str;
	int index = 0;
	cout<<S1<<"__\n";
	
	findPermutationUtil(S1 , j , str.length() , plot , -1 , S , index);
}

int main()
{
	string str = "AABC";
	map<char, int> plot;
	
	findPermutation(str , str.length() , plot);
}
