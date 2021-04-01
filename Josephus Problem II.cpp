#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

template<class T> 
using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


/*
Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order. 
It performs all the operations as performed by the set data structure in STL in log(n) complexity
and performs two additional operations also in log(n) complexity .

order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).

null_type : It is the mapped policy. It is null here to use it as a set.
If we want to get map but not the set, as the second argument type must be used mapped type.

*/
int main()
{   
    ll n,k;
    cin>>n>>k;
    oset<ll>s;
    for(ll i=1;i<=n;i++)
    {
        s.insert(i);
    }
    ll pos=k%n;
    while(s.size())
    {
        ll value=*s.find_by_order(pos);
        cout<<value<<" ";
        s.erase(value);
        if(s.size())
        {
            pos=(pos+k)%(s.size());
        }
    }
}