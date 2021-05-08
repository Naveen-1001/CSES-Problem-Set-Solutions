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

struct Comp {
  bool operator()(const std::pair<pair<ll, ll>,ll> &a, const std::pair<pair<ll,ll>,ll> &b) {
    if (a.first.first != b.first.first) {
      return a.first.first < b.first.first;
    }
    return a.first.second > b.first.second;
  }
};

//Logic:-
/*
To find the vector of if the range contains another range, sort the values in inc. order 
of closing range but dec. order of opening range. So when we get a closing value, if the opening value
is less than any other opening  value, then it contains that value as the closing ranges are already in
inc. order.

To find the vector if the range is inside another range, sort the values in asc order of the opening values
and the dec order of the closing values. So wheneevr we check for a range, we check if the closing value is
less than any other closing value. If yes, then this range is inside that range as the opening s already
after that range. 

*/

void solve()
{
    //check t
    ll n;
    cin>>n;
    vector<ll>contains(n);
    vector<ll>inside(n);
    vector<pair<pair<ll,ll>,ll>>v;
    ll p,q;
    for(ll i=0;i<n;i++)
    {   
        cin>>p>>q;
        v.push_back({{p,q},i});
    }
    set<pair<ll,ll>>s;
    //v needs to be in increasing order of opening intervals and dec. closing
    Comp comp_functor;
    sort(v.begin(),v.end(),comp_functor);
    /*
    cout<<"Inc. order of opening\n";
    for(ll i=0;i<n;i++)
    {
        cout<<v[i].first.first<<" "<<v[i].first.second<<"--> index= "<<v[i].second<<"\n";
    }
    */
    for(ll i=0;i<n;i++)
    {
        auto it=s.lower_bound({v[i].first.second,0});
        if(it!=s.end())
        {
            inside[v[i].second]=1;
        }
        s.insert({v[i].first.second,v[i].second});
    }
    s.clear();

    //v needs to be in asc. order of closing intervals
    for(ll i=0;i<n;i++)
    {
        ll temp=v[i].first.first;
        v[i].first.first=v[i].first.second;
        v[i].first.second=temp;
    }
    //now closing is first element of pair
    sort(v.begin(),v.end(),comp_functor);
    /*
    cout<<"Inc. order of closing\n";
    for(ll i=0;i<n;i++)
    {
        cout<<v[i].first.first<<" "<<v[i].first.second<<"--> index= "<<v[i].second<<"\n";
    }
    */
    
    for(ll i=0;i<n;i++)
    {
        auto it=s.lower_bound({v[i].first.second,0});
        if(it!=s.end())
        {
            contains[v[i].second]=1;
        }
        s.insert({v[i].first.second,v[i].second});
    }
    //cout<<"\n";
    for(ll i=0;i<n;i++)
    {
        cout<<contains[i]<<" ";
    }
    cout<<"\n";
    for(ll i=0;i<n;i++)
    {
        cout<<inside[i]<<" ";
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