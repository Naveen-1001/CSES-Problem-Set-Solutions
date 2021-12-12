#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


/*
In this question, first step would be to think of the brute force solution. For this, we would
have to check the sum of the contunguous subarrays from each index of length from a to b. An easy way to check the
sum would be to use prefix arrays. So using this, even though we can find the sum in O(1) time, we would have to check
all possible lengths from each of the possible indices. This would reach a time coplexity of O(n*(b-a)) whihc is O(n^2)
in the worst case.
To improve this, we have to analyse hiw we would arrauve at the solution. 
Say we are at  index i and we have ranges of a,b for length of the subarrays. Then, to find the max sum among these,
we would check the max of prefix(i+j)-prefix[i-1] where j varies from a-1 to b-1. Here, the trick is that prefix[i-1] is
constant in all of these. So if we just get the maximum of the prefix[i+j], we would have to compare prefix[i+jmax]-prefix[i-1]
with the current answer. Also, when we check the next index, we would add one element to this window and remove the last element.
This  can be done in O(log(b-a)) time using sets. For the next window everything would be same, just we have to subtract from prefix[inew-1].

The time complexity of this approach is O(n*log(b-a)).

The triick is to think of optimized brute force i.e O(n(b-a)) and not O(n^2)  when thinking of the brute force. Otherwise
arriving at this approach is not very intuitive.
*/

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<ll>prefix(n);
    prefix[0]=v[0];
    for(ll i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+v[i];
    }
    ll ans=LONG_LONG_MIN;
    multiset<pair<ll,ll>,greater<pair<ll,ll>>>s;
    for(ll i=a-1;i<b-1;i++)
    {
        s.insert({prefix[i],i});
    }
    for(ll i=0;i<n;i++)
    {
        if(i+a-2>=0) s.erase({prefix[i+a-2],i+a-2});
        if(i+b-1<n) s.insert({prefix[i+b-1],i+b-1});
        if(!s.empty()) ans=max(ans, (*(s.begin())).first-((i-1>=0)?prefix[i-1]:0));
        //cout<<ans<<"-\n";
    }
    cout<<ans;
}