#include<bits/stdc++.h>
#include<stdio.h>

#define max 6
using namespace std;
int queue[max],f=-1,r=-1;
int f1();
int ir();
int df();
int dr();
int display();
int main()
{int n;
	do{
	cout<<"1. insertion from front "<<"\n";
	cout<<"2. insertion from rear "<<"\n";
	cout<<"3. deletion from front "<<"\n";
	cout<<"4. deletion from front "<<"\n";
	cout<<"5. display "<<"\n";
	cout<<"6. exit";
	cout<<"enter ur choice";
	cin>>n;
	switch(n){
		case 1: f1();
		break;
		case 2: ir();
		break;
		case 3: df();
		break;
		case 4: dr();
		break;
		case 5: display();
		break;
		case 6: exit(0);
	}
	}while(n<=6);
    return 0;	
	}
int f1()
{
	int a;
	if(f==5)
{
	cout<<"overflow"<<"\n";
}
	else
{

	  if((f==-1)&&(r==-1))
    {f=f+1;
       r=r+1;
	}	
    if(f>0)
    {f=f-1;
    }
    cout<<"enter element"<<"\n";
     cin>>a;
    queue[f] =a;
    cout<<" element is"<<queue[f];
}
return 0;
}
int ir()
{
	int a;
	if(r==max-1)
	{
	cout<<"overflow"<<"\n";
    }
	else
 {
	r=r+1;
	cout<<"enter element"<<"\n";
	cin>>a;
	queue[r]=a;
  }
  return 0;
}


int df()
  {
	int a;
	if(f==-1||r==-1)
	{
		cout<<"underflow"<<"\n";
	}
    a=queue[f];
    f=f+1;
    cout<<"deleting element is"<<a;
    return 0;
}
int rf()
  {
	int a;
	if(r==-1)
	{
		cout<<"underflow";
	}
	else
	{
		a=queue[r];
		r=r-1;
		cout<<"deleting element is"<<a;
	}
	return 0;
}

int display()
   {
	if(f<=r)
	{
		cout<<"status of queue \n";
		for(int i=f;i<=r;i++)
		{
			cout<<queue[i];
		} 
	}
		else
		{
		
		cout<<"queue is empty";
	     }    
return 0;
   }

