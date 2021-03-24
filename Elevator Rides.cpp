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

void solve()
{
    //check t
    int n,w;
    cin>>n>>w;
    vector<ll>v(n+1);
    for(ll i=1;i<n+1;i++)
    {
        cin>>v[i];
    }

    vector<pair<ll,ll>>dp((1<<n)+1);
    dp[0]={1,0};

    for(ll i=1;i<(1<<n);i++)
    {
        dp[i]={n+1,0};

        for(ll j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                auto option=dp[i^(1<<j)];
                if(option.second+v[j+1]<=w)
                {
                    option.second+=v[j+1];
                }
                else
                {
                    option.first++;
                    option.second=v[j+1];
                }

                dp[i]=min(dp[i],option);
            }
        }
    }
    /*
    for(ll i=0;i<(1<<n);i++)
    {
        cout<<dp[i].first<<" "<<dp[i].second<<"\n";
    }
    */
    cout<<dp[(1<<n)-1].first;
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