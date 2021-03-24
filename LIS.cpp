#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;
/*
The time complexity of this solution is O(n^2)
ll lIS(ll n, vector<ll>v)
{
    vector<ll>dp(n,1);

    ll maximum=1;
Basically we store the max length of inc subsequrnce that element can be part of in dp[i].
to find the max, at end ,we have to iterate thorugh the dp length once.
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(v[i]>v[j]) 
            {
                dp[i]=max(dp[i],1+dp[j]);
                maximum=max(maximum,dp[i]);
            }
        }
    }
    return maximum;
}   
*/

/*
We can store the values in another way that is at dp[i] we store the last elemnt of the increasinng subsequence of length i+1.

as we go through the array, if we get the element larger than last element of largest inc subseqnce till now, we get a new length subsequence,
otherwise, suppose we get that it is less than dp[i]. it means that there exists a subsequnce of tlenght i-1(stored in prev index) whose last element is
smaller than the current element. So if we combine the last subsequence with the current element , we get the smallest element with subsequnnce length i; 
*/

ll lIS(ll n, vector<ll>v)
{
    vector<ll>dp;

    for(ll i=0;i<n;i++)
    {
        auto it=lower_bound(dp.begin(),dp.end(),v[i]);

        if(it==dp.end())
        {
            dp.push_back(v[i]);
        }
        else
        {
            *it=v[i];
        }
    }

    return dp.size();
}

int main()
{   
    ll n;
    cin>>n;
    vector<ll>v(n);

    for(ll i=0;i<n;i++)
        cin>>v[i];

    cout<<lIS(n,v);
    return 0;
}