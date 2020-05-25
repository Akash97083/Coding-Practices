#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long  i , j , k , l , t, n, a;
    
    scanf("%lld",&t);
    
    while(t--)
    {
        scanf("%lld",&n);
        stack<int> stValue, stIndex;
        
        vector<int> vec;
        int fre[100001] = {0};
        for(i = 0; i < n; i++)
        {
            scanf("%lld",&a);
            vec.push_back(a);
            fre[a] = fre[a] + 1;
        }
        
       
        long long ans[100000] = {0};
        
        for(i = 0; i < n; i++)
        {
            if(!stValue.empty())
            {
                while(!stValue.empty() && stValue.top() < fre[vec[i]])
                {
                    ans[stIndex.top()] = vec[i];
                    stIndex.pop();
                    stValue.pop();
                }
            }
            stIndex.push(i);
            stValue.push(fre[vec[i]]);
        }
        
        for(i = 0; i < n; i++)
        {
            if(ans[i] == 0) printf("-1 ");
            else printf("%lld ",ans[i]);
        }
        printf("\n");
    }
}