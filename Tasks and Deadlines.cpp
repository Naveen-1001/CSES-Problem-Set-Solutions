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
The fact that we can simmply sort it pon the basis of the duration and do the task wih the
least duration first is that whenever we atre doing a task, we are also wasting the time of the
tasks. So if we do the tasks with the more dutration first, then we are simply wasting the tme of the 
other tasks with less duration.
The reason this works is that the tasks do not have any weights. So if we do a light duration task first
then we are doing the most amount of tasks per unit time in the beginning. So this  is the optimal way. 
*/
void solve()
{
    //check t
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v;
    ll du,dl;
    for(ll i=0;i<n;i++)
    {
        cin>>du>>dl;
        v.push_back({du,dl});
    }
    sort(v.begin(),v.end());
    ll time=0;
    ll award=0;
    for(ll i=0;i<n;i++)
    {
        time=time+v[i].first;
        award=award+(v[i].second-time);
    }
    cout<<award<<"\n";
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