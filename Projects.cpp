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
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    vector<ll>p(n);
    //Basically we want to reduce the number of days we check cuz inititlayy b[i] and a[i] can go uptill 10^9.
    // But we actually only care abt the days either a job has been completed or finished. Also for that we dont
    // need the exact day. we only want the relative positions of the staring and ending dates to be the same.
    // So we assign an index to each of the starting or ending days. Then we run a dp over these days. We store
    // starting date and price for a project at the same index as the index assigned for the ending date of the job.

    map<ll,ll>compress;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>p[i];
        compress[a[i]];
        b[i]++;
        compress[b[i]];
    }

    ll counter=0;
    for(auto it=compress.begin();it!=compress.end();it++)
    {
        it->second=counter++;
    }

    vector<vector<pair<ll,ll>>>v(counter);
    //vector of vectors cause more than 1 project may have the same ending dates
    for(ll i=0;i<n;i++)
    {
        v[compress[b[i]]].emplace_back(compress[a[i]],p[i]);
    }

    vector<ll>dp(counter);

    for(ll i=0;i<counter;i++)
    {
        if(i>0)
        {
            dp[i]=dp[i-1];
        }
        //check all the projects that ended on that day
        for(auto x:v[i])
        {  
            //dp[x.first] gives max profit possible before starting current project 
            dp[i]=max(dp[i],dp[x.first]+x.second);
        }
    }

    cout<<dp[counter-1];    
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