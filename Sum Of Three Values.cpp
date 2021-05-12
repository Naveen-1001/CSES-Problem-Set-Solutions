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
    ll n,x;
    cin>>n>>x;
    ll val;
    vector<pair<ll,ll>>v;
    for(ll i=1;i<=n;i++)
    {
        cin>>val;
        v.push_back({val,i});
    }
    sort(v.begin(),v.end());
    /*
    for(ll i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    */
    for(ll i=0;i<n-2;i++)
    {
        ll l=i+1,r=n-1;
        while(l<r)
        {
            if(v[i].first+v[l].first+v[r].first==x)
            {
                cout<<v[i].second<<" "<<v[l].second<<" "<<v[r].second<<"\n";
                return;
            }
            if(v[i].first+v[l].first+v[r].first<x)
            {
                l++;
                continue;
            }
            r--;
        }
    }
    cout<<"IMPOSSIBLE";
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