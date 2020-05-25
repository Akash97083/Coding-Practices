#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    
    cin>>t;
    
    while(t--)
    {
        long long n, a;
        
        vector<long long> vec;
        
        cin>>n;
         long long ans[1000005] = {0};
         
        for(long long i = 0; i < n; i++)
        {
            cin>>a;
            
            vec.push_back(a);
            
            ans[i] = 1;
        }
        
        stack<pair<long long, long long> > st;
        
       
        for(long long i = 0; i < n; i++)
        {
             while(!st.empty() && st.top().first <= vec[i])
             {
                 ans[i] += st.top().second;
                 st.pop();
             }
            st.push(make_pair(vec[i],ans[i]) );
        }
        
        for(long long i = 0; i < n; i++){
            
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}