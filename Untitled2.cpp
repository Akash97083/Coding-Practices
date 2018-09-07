#include <bits/stdc++.h>

using namespace std;

#define MAX 10

int main()
{
	int attempt = 0;
	int x, y;
	int initial_x, initial_y;
	char initital_direction;
	string command_list;
	
	// 10 x 10, 2-dimensional grid
	// condsider  [0 - 9][0 - 9] range of [x][y] 
	
	//validate [x, y] is in matrix range or not	
	do {
		if(attempt != 0) {
			cout<<"\nPlease enter valid location in range [0 - 9][0 - 9] :\n";
		}
		if(attempt > 2) {
			cout<<"\n You have misunderstood this code :\n";
			cout<<"\n Thank you for using it :\n";
			return 0;
		}
		
		cout<<"\n Please enter the initial location of the robot (x,y) :";
		cin>>x>>y;	
		attempt++;
	}while(x < 0 || x >= 10 || y < 0 || y >= 10);
	
	attempt = 0;
	
	do {
		if(attempt != 0) {
			cout<<"\nPlease enter valid direction ['F', 'L', 'R'] ( F=Forward, L=Left, R=Right ):\n";
		}
		if(attempt > 2) {
			cout<<"\n You have misunderstood this code :\n";
			cout<<"\n Thank you for using it :\n";
			return 0;
		}
		cout<<"\n Please enter the initial direction of the robot :";
		cin>>initital_direction;
		attempt++;
	} while(initital_direction != 'F' && initital_direction != 'R' && initital_direction != 'L');

	
	cout<<"\n Please enter a command list :";
	cin>>command_list;
	
	initial_x = x;
	initial_y = y;
//	cout<<"hellp";
	for(int i = 0; i < command_list.length(); i++) {
			
		if(command_list[i] == 'F') {
				if(y < 9) y++;
				else cout<<"\n At Matrix Corner direction move droped : " <<command_list[i]<<" \n";
		}
		else if(command_list[i] == 'R') {
				if(x < 9) x++;
				else cout<<"\n At Matrix Corner direction move droped : " <<command_list[i]<<" \n";
		}
		else if(command_list[i] == 'L') {
				if(x > 0) x--;
				else cout<<"\n At Matrix Corner direction move droped : " <<command_list[i]<<" \n";
		}
		else if(command_list[i] != ',' && command_list[i] != ' ' ){
			cout<<"\n Unknown direction move droped : " <<command_list[i]<<" \n\n";
		}
		
	}
	
	cout<<"The new position of the robot is : "<<x<<" "<<y <<"\n\n";
	
	cout<<"Shortest path from the origin ( Multiple route may possible ): ";
	attempt = 0;
	for(int i = 0 ; i < y-initial_y ; i++) {
		if(attempt != 0){
			cout<<",";
		}
		attempt++;
		cout<<"F";
	}
	if((initial_x - x) < 0) {
		for(int i = 0 ; i < x-initial_x ; i++) {
			if(attempt != 0){
					cout<<",";
			}
			attempt++;
			cout<<"R";
		}
	}
	else {
		for(int i = 0 ; i < initial_x - x ; i++) {
			if(attempt != 0){
					cout<<",";
			}
			attempt++;
			cout<<"L";
		}	
	}
	
	if(attempt == 0) {
		cout<<"no need to move";
	}
	return 0;
}
