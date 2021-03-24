#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<ll>());
    //Set the remaining space in each gondola after plaing one element into a set. 
    //Fill the next element if possible after which erase it as only 2 children can be in one gondola
    multiset<ll>space;
    //if dont use multi set, then fail for cases eg. 4 10, 7 7 3 3...correct ans 2 but will give 3 since only one 3 will be stored in space set after 7 7.
    ll count=0;
    for(ll i=0;i<n;i++)
    {
        auto it=space.lower_bound(v[i]);
        if(it==space.end())
        {
            space.insert(x-v[i]);
            count++;
        }
        else
        {
            space.erase(it);
        }
    }
    cout<<count;
}