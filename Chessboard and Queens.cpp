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

ll res=0;

void count(ll y,ll n,vector<string>board,vector<ll>column,vector<ll>diag1,vector<ll>diag2)
{   
    if(y==n)
    {
        res++;
        return;
    }

    for(ll x=0;x<n;x++)//checking all the columns of row y
    {
        if(column[x] || diag2[x+y] || diag1[x-y+n-1] || board[y][x]=='*') continue;
        column[x]=diag1[x-y+n-1]=diag2[x+y]=1;
        count(y+1,n,board,column,diag1,diag2);
        column[x]=diag1[x-y+n-1]=diag2[x+y]=0;
    }
}

void solve()
{   
    ll n=8;
    vector<string>board(n);
    for(ll i=0;i<n;i++)
    {
        string str;
        cin>>str;
        board[i]=str;
    }
    vector<ll>column(n);
    vector<ll>diag1(2*n);//other diagnol: x-y+n-1
    vector<ll>diag2(2*n);//main diagnal: x+y
    count(0,n,board,column,diag1,diag2);
    cout<<res;
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