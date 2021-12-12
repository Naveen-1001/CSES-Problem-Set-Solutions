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
/*
order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).
*/

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
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    vector<ll>ans;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    multiset<ll>a,b;
    ll sum_a=0,sum_b=0;
    for(ll i=0;i<n;i++)
    {
        if(i-k>=0)
        {
            auto it=b.lower_bound(v[i-k]);
            if(it!=b.end() and *it==v[i-k])
            {   
                sum_b-=*it;
                b.erase(it);
            }
            else
            {
                it=a.lower_bound(v[i-k]);
                sum_a-=*it;
                a.erase(it);
            }
            if(a.size()>b.size())
            {
                auto it_e=a.end();
                it_e--;
                ll val=*it_e;
                sum_a-=val;
                sum_b+=val;
                a.erase(it_e);
                b.insert(val);
            }
            else if (b.size()-a.size()>1)
            {   
                auto it_e=b.begin();
                ll val=*it_e;
                sum_b-=val;
                sum_a+=val;
                b.erase(it_e);
                a.insert(val);
            }
        }
        if(b.empty() or *(b.begin())<=v[i])
        {
            b.insert(v[i]);
            sum_b+=v[i];
        }
        else
        {
            a.insert(v[i]);
            sum_a+=v[i];
        }
        if(a.size()>b.size())
        {
            auto it_e=a.end();
            it_e--;
            ll val=*it_e;
            sum_a-=val;
            sum_b+=val;
            a.erase(it_e);
            b.insert(val);
        }
        else if (b.size()-a.size()>1)
        {   
            auto it_e=b.begin();
            ll val=*it_e;
            b.erase(it_e);
            sum_a+=val;
            sum_b-=val;
            a.insert(val);
        }
        /*
        cout<<"A:- ";
        for(auto it=a.begin();it!=a.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
        cout<<"B:- ";
        for(auto it=b.begin();it!=b.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
        cout<<"sum_a:- "<<sum_a<<", sum_b:- "<<sum_b<<"\n\n";
        */
        ll median=*(b.begin());
        if(i>=k-1) ans.push_back(sum_b-(b.size()*median)+(a.size()*median)-sum_a);
    }
    for(ll i=0;i<n-k+1;i++)
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