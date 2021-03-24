#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>required(n);
    vector<ll>available(m);
    for(ll i=0;i<n;i++){
        cin>>required[i];
    }
    for(ll i=0;i<m;i++){
        cin>>available[i];
    }
    sort(available.begin(),available.end());
    sort(required.begin(),required.end());
    ll ap=0,rp=0,count=0;
    while(ap<m and rp<n){
        if(abs(available[ap]-required[rp])<=k){
            count++;
            ap++;
            rp++;
            continue;
        }
        if(required[rp]>available[ap]){
            ap++;
        }
        else{
            rp++;
        }
    }
    cout<<count;   
}