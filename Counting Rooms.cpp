#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll m,n;
    cin>>m>>n;
    vector<vector<char>>grid(m,vector<char>(n));
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {   
            char ch;
            cin>>ch;
            grid[i][j]=ch;
        }
    }
    ll count=0;
    queue<pair<ll,ll>>q;
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(grid[i][j]=='.')
            {
                count++;
                q.push({i,j});
                grid[i][j]='#';
                while(!q.empty())
                {
                    pair<ll,ll>front=q.front();
                    q.pop();
                    ll r=front.first,c=front.second;
                    if(r+1<m and grid[r+1][c]=='.')
                    {   
                        grid[r+1][c]='#';
                        q.push({r+1,c});
                    }
                    if(r-1>=0 and grid[r-1][c]=='.')
                    {   
                        grid[r-1][c]='#';
                        q.push({r-1,c});
                    }
                    if(c+1<n and grid[r][c+1]=='.')
                    {   
                        grid[r][c+1]='#';
                        q.push({r,c+1});
                    }
                    if(c-1>=0 and grid[r][c-1]=='.')
                    {   
                        grid[r][c-1]='#';
                        q.push({r,c-1});
                    }
                }
            }
        }
    }
    cout<<count;
}