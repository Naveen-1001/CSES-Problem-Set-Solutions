#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans=1;
    for(ll i=0;i<n;i++)
    {
        if(v[i]<=ans)
        {
            ans=ans+v[i];
        }
        else break;
    }
    /*
    The main logic behind this algorithm is that suppose we want to find if the sum x can be created. 
    Then it means that the sum 1 to x-1 can be created since we are going form 1 to x in inceasing order.
    So if the number currently in the array is x-i, then since we already know a method to find the sum of x-i, then
    we can just include this in the solution. So i can be in the range 0 to x.
    The main reason we update the answer with x+v[i] is that since we know we can already create a subset for sum
    x-1 without including the number v[i], then it means that from the information we have currently,
    the max sum we can create is x-1+v[i]. So the next sum we have to check is x+v[i].
    */
    cout<<ans;
}