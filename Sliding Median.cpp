#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace __gnu_pbds;
using namespace std;

template<class T> 
using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


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

void solve()
{
    //check t
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    ordered_set<pair<ll,ll>>s;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(ll i=0;i<k-1;i++)
    {   
        s.insert({v[i],i});
    }
    vector<ll>ans;
    for(ll i=k-1;i<n;i++)
    {
        if(i-k>=0) s.erase({v[i-k],i-k});
        s.insert({v[i],i});
        ans.push_back((*s.find_by_order((k-1)/2)).first);
    }
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
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