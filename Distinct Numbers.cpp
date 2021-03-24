#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    set<ll>s;
    int var;
    for(ll i=0;i<n;i++)
    {
        cin>>var;
        s.insert(var);
    }
    cout<<s.size();
    return 0;
}