#include<bits/stdc++.h>

using namespace std;

struct node {
    char data;
    struct node * next;
};

struct node * insert(struct node* top, char c)
{
    struct node *temp;
    
    
    temp = (struct node *)malloc(sizeof(struct node));
    
    temp->next = top;
    temp->data = c;
    
    
    return temp;
}

int main()
{
    long long t, i , j , k , l;
    
    cin>>t;
    
    string c;
    
    while(t--)
    {
        struct node * top = NULL;
        cin>>c;
        
        i = 0;
        int flag = 0;
        while(c[i])
        {
            if(c[i] == '[' || c[i] == '{' || c[i] == '(')
            {
                top = insert(top, c[i]);
            }
            else 
            {
                char val;
                if(top == NULL) {
                    flag = 1;
                    break;
                }
                else {
                    val = top->data;
                    top = top->next;
                }
                
                if((val == '(' && c[i] != ')') ||
                        (val == '[' && c[i] != ']') ||
                            (val == '{' && c[i] != '}') )
                    {
                    flag = 1;
                    break;
                    }
                
            }
            i++;
        }    
        
        if(flag == 1 || top != NULL)
        {
            cout<<"NO\n";
        }
        else cout<<"YES\n";
       cout<<"\n";
    }
}