#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a,i, j , k, l, m, n;
    
    cin>>n;
    
    vector<long long> vec;
    
    for(long long i = 0; i < n; i ++)
    {
        cin>>a;
        vec.push_back(a);
    }
    
    stack<pair<long long, long long>> st;
    
    long long count = 0;
    
    for(long long  i = 0; i < n; i++)
    {
        while(!st.empty() && st.top().first < vec[i])
        {
            count +=st.top().second;
            st.pop();
        }
        if(st.empty())
        {
            st.push(make_pair(vec[i],1));
            
        } else if(st.top().first == vec[i])
        {
            count += st.top().second;
            
            if(st.size() > 1) count++;
            
            st.top().second++;
           // st.push(make_pair(vec[i],1));
        }
        else {
            count++;
            st.push(make_pair(vec[i],1));
        }
    }
    
    cout<<count<<"\n";
}