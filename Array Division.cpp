#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//the max sum partition can have sum from the largest number in the array to infinity. 
/*
So lets say we want to check if the max sum<=x is possible. We start a running sum from the beginning
and check if the number of partitions in which it is possible to do this is <=k. If yes, then it
means that a this is to the right(or on) the partition point. This is because, if we can create partitions
in the array in less than k partitions such that the sum is less than or equal to x in each partition, then 
there must be a number which is either x or to the right of it such that if we make one more partition, the 
max sum partition is less than x.
Since the problem is of the form n n n y y y and we have to find the partition point, we use binary search.
*/
int main()
{
    ll n,k,mn;
    cin>>n>>k;
    mn=LONG_LONG_MIN;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mn=max(mn,v[i]);
    }
    ll mx=LONG_LONG_MAX,mid,ans=LONG_LONG_MAX;
    while(mn<=mx)
    {   
        mid=mn+(mx-mn)/2;
        //cout<<mn<<" "<<mid<<" "<<mx<<"\n";
        ll count=1,c_sum=0,flag=0,max_sum=0;
        for(int i=0;i<n;i++)
        {   
            if(v[i]>mid)
            {   
                flag=1;
                break;
            }
            c_sum+=v[i];
            if(c_sum>mid)
            {
                count++;
                c_sum=v[i];
            }
        }
        if(flag==1 or count>k)
        {
            mn=mid+1;
        }
        else if(count<=k)
        {   
            mx=mid-1;
            ans=min(ans, mid);
        }
    }
    cout<<ans;
}