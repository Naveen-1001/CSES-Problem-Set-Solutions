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
    ll sum=0;
    //We dont know exactly what the number will be. But we can still find out the sum.
    //We know its best if the number is somewhere between the middle two elements whene the array is sorted.
    //But whatever it is, the sum of difference of the values will be the same as the difference between the 
    //elements at symmetrically opposite positions in the array.

    sort(v.begin(),v.end());
    for(ll i=0;i<n/2;i++)
    {
        sum=(sum+v[n-i-1]-v[i]);
    } 
    cout<<sum;
    return 0;
}