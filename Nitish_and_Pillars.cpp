#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i , j, k , l , m , n, q, a, b;
    
    vector<int> vec;
    
    cin>>n;
    
    for(i = 0; i < n; i++)
    {
        cin>>m;
        vec.push_back(m);
    }
    
    long long arr[100000] = {-1};
    
    int flag = 0;
    for(i = 0; i < n; i++)
    {
        flag = 0;
        for(j = i+1; j < n; j++)
        {
            if(vec[i] < vec[j])
            {
                arr[i] = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0) arr[i] = -1;
    }
    
    cin>>q;
    
    long long count = 0;
    for(i = 0; i < q; i++)
    {
        cin>>a>>b;
        count = 0;
      //  cout<<"\n";
        while(a <= b && a != -1)
        {
         //   cout<<vec[arr[a]]<<" ";
            a = arr[a];
            count++;
        }
    //    cout<<"\n";
        cout<<count<<"\n";
    }
    
    return 0;
}