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
/*
Logic:-
for each index, we can count the number of valid subarrays ending at that point. We keep on 
adding the elements to a map. For each index, after adding it to the map, we check if the 
size of the map is<=k. If yes, then the number of subarrays we can have is 
current_index-(index from which the elements are present in our map). If the size of the map is larger
than k, we remmove elements from the (beginning position from where the map currently contains elements)
(l=0 in the beginning) till the size of the map<=k. This does not affect our ans as if at any point,
the map size>k, then this will even be true for next elements. So we will have to remove them for them also.
*/
void solve()
{
    //check t
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<ll,ll>m;
    int l=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        m[v[i]]++;
        while(m.size()>k)
        {
            m[v[l]]--;
            if(m[v[l]]==0)
            {
                m.erase(v[l]);
            }
            l++;
        }
        ans+=i-l+1;
    }
    cout<<ans;
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