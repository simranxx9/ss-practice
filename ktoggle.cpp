#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    int mat[n][m];
    
    for(int i = 0 ; i < n ; i ++ )
    {
        for(int j = 0 ; j < m ; j++ )
        {
            cin >> mat[i][j];
        }
    }
    
    map<string, int> mp;
    
    for(int i = 0; i < n ; i ++ )
    {
        string temp = "";
        for(int j =0 ; j < m; j ++ )
        {
            temp += mat[i][j];
        }
        if(mp.find(temp) != mp.end() )
        {
            // int oldFreq = mp[temp];
            mp[temp] ++ ;
        }
        else
            mp[temp] = 1;
    }
    int ans = INT_MIN;
    
    for(auto it : mp)
    {
        int num_zeroes = 0;
        for(int i = 0 ; i < it.first.length() ; i ++ )
        {
            if(it.first[i] == '0') num_zeroes++;
        }
        if( num_zeroes <= k and (k - num_zeroes)%2 == 0 )
            ans = max(it.second, ans);
    }
    
    cout<<ans<<endl;
}
