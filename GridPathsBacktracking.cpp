#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll fast_power(ll a, ll b, ll m)//a^b
{
    if(b==0) return 1;
    if(b==1) return a;

    ll temp=fast_power(a,b/2,m);

    if(b%2==0) return (temp*temp)%m;
    return ((temp*temp)%m*a)%m;
}

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b); 
}

ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

ll sum_of_digits(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

bool visited[7][7];

bool e(int i,int j)
{
    if(i>=0 and j>=0 and i<7 and j<7 and !visited[i][j]) return true;
    return false;
}

ll Count=0;
string s;

void dfs(int i,int j,int a=0)
{
    if(i==6 and j==0)
    {
        if(a==48) Count++;//(Opt 2)
        return;
    }
    visited[i][j]=true;

    if(s[a]=='?' or s[a]=='L')
    {
        if(j>0 and !visited[i][j-1])
        {
            if(!(!e(i,j-2) and e(i-1,j-1) and e(i+1,j-1)))//Check the wall condition(Opt 3 and 4)
            {
                dfs(i,j-1,a+1);
            }
        }
    }

    if(s[a]=='?' or s[a]=='R')
    {
        if(j<6 and !visited[i][j+1])
        {
            if(!(!e(i,j+2) and e(i-1,j+1) and e(i+1,j+1)))
            {
                dfs(i,j+1,a+1);
            }
        }
    }

    if(s[a]=='?' or s[a]=='U')
    {
        if(i>0 and !visited[i-1][j])
        {
            if(!(!e(i-2,j) and e(i-1,j-1) and e(i-1,j+1)))
            {
                dfs(i-1,j,a+1);
            }
        }
    }

    if(s[a]=='?' or s[a]=='D')
    {
        if(i<6 and !visited[i+1][j])
        {
            if(!(!e(i+2,j) and e(i+1,j+1) and e(i+1,j-1)))
            {
                dfs(i+1,j,a+1);
            }
        }
    }

    visited[i][j]=false;
}

void solve()
{
    cin>>s;
    dfs(0,0);
    cout<<Count;
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {   
        solve();
    }
    return 0;
}
