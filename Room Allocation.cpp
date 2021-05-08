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
    ll n,p,q;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>>v;
    for(ll i=0;i<n;i++)
    {
        cin>>p>>q;
        v.push_back({{p,q},i});
    }
    ll k=1;
    sort(v.begin(),v.end());
    multiset<pair<ll,ll>>rooms;
    map<ll,ll>m;
    /*
    Basically sort the values in order of incoming customers. For each customer find the latest
    cleared room using binary search by keeping the departured time for each of the rooms in the 
    rooms multiset. Since we also have to show the allocate droom for each of the custome, we keep
    track of the customer index which last occupied the room incase we need it later i.e when
    we use the same room again.
    */
    for(ll i=0;i<n;i++)
    {   
        auto it=rooms.lower_bound({v[i].first.first,0});
        if(it!=rooms.end())
        {
            if(it!=rooms.begin())
            {   
                it--;
                m[v[i].second]=m[(*it).second];
                rooms.erase(it);
            }
            else m[v[i].second]=k++;
            rooms.insert({v[i].first.second,v[i].second});
        }
        else 
        {
            if(rooms.size())
            {
                auto itt=rooms.end();
                itt--;
                m[v[i].second]=m[(*itt).second];
                rooms.erase(itt);
            }
            else
            {
                m[v[i].second]=k++;
            }
            rooms.insert({v[i].first.second,v[i].second});
        }
    }
    cout<<rooms.size()<<"\n";
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";
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