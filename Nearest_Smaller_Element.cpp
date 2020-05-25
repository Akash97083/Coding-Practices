#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a, n;
    
//    cin>>n;
    scanf("%lld",&n);
    stack<int> st;
    long long m = 99999999;
    
    for(long long i = 0; i <n; i++)
    {
        //cin>>a;
        scanf("%lld",&a);
        
        if(m < a) printf("-1 ");//cout<<"-1 ";
        else {
            
           stack<int> tmp = st;
           
           
           while(!tmp.empty() && a <= tmp.top()){
               
               tmp.pop();
           }
           
            if(tmp.empty()) printf("-1 ");//cout<<"-1 ";
            else printf("%lld ",tmp.top()); //cout<<tmp.top()<<" ";
            
            while(!st.empty() && a <= st.top())
            {
                st.pop();
            }
            st.push(a);
            
          
            if(m > a) a = m;
        }
    }
}