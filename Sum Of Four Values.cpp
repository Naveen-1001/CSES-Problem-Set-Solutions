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
    /*
    //check t
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++)
    {   
        ll val;
        cin>>val;
        v.push_back({val,i+1});
    }
    cout<<"Done\n";
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++)
    {
        cout<<i<<" "<<v[i].first<<"\n";
    }
    cout<<"\n";
    for(ll i=0;i<n-3;i++)
    {   
        ll l=i+1;
        ll r=n-1;
        while(l<r-1)
        {   
            ll req=k-(v[i].first+v[l].first+v[r].first);
            pair<ll,ll>p={req,0ll};
            auto it=lower_bound(v.begin()+l+1,v.begin()+r,p);
            if(it==v.begin()+r)
            {
                l++;
            }
            else if((*it).first==req)
            {
                cout<<v[i].second<<" "<<v[l].second<<" "<<(*it).second<<" "<<v[r].second;
                return;
            }
            else if((*it).first>req)
            {
                r--;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    */
   
    map<ll,vector<pair<ll,ll>>>m;
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {   
            m[v[i]+v[j]].push_back({i,j});
        }
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(m.find(k-it->first)!=m.end())
        {
            vector<pair<ll,ll>>current=it->second;
            vector<pair<ll,ll>>found=m[k-it->first];
            for(int k=0;k<found.size();k++)
            {   
                for(int i=0;i<current.size();i++)
                {
                    if(current[i].first!=found[k].first and current[i].second!=found[k].second and current[i].second!=found[k].first and current[i].first!=found[k].second)
                    {
                        cout<<current[i].first<<" "<<current[i].second<<" "<<found[k].first<<" "<<found[k].second;
                        return;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    /*
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;++i)
    {
    	ll xx;
    	cin>>xx;
    	a[i]=xx;
    	v[i]={xx,i};
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			int low=j+1,hi=n-1;
			while(low<hi)
			{
				int p=v[i].first,q=v[j].first,r=v[low].first,s=v[hi].first;
				if(p+q+r+s==x)
				{
					cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[low].second+1<<" "<<v[hi].second+1<<endl;
                    return;
				}
				else if(p+q+r+s<x)low++;
				else hi--;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
    */
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