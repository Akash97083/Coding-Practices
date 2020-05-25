#include<bits/stdc++.h>

using namespace std;

struct node {
    
    long long number;
    long long minnumber;
    string name;
    struct node * next;
};

struct node * insert(struct node * top, long long number, string name)
{
    if(top == NULL)
    {
        top = (struct node *) malloc(sizeof(struct node));
        
        top->number = number;
        top->minnumber = number;
        top->name = name;
        return top;
    }
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    
    temp->number = number;
    temp->minnumber = min(top->minnumber, number);
    temp->name = name;
    temp->next = top;
    
    return temp;
}

int main()
{
   long long i , j , k , l , t, n ;
   string name;
   
   cin>>t;
   
   while(t--)
   {
        struct node *top;
        
        cin>>n;
        if(n != -1)
        {
            cin>>name;
            if(n != 0)
            top = insert(top , n, name);
        }
        else {
            long long count = 0;
            while(top->number != top->minnumber)
            {
                top = top->next;
                count++;
            }
            cout<<count<<" "<<top->name<<"\n";
            top = top->next;
        }
   }
    
}
