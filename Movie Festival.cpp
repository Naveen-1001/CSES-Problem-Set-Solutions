#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//Idea is that we have to iterarte oer all the compressed times and at each step see the movie with the least end time
// depending whether we can/or are seeing the movie from the beginning
int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    map<ll,ll>compress;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        compress[a[i]];
        compress[b[i]];
    }
    ll counter=0;
    for(auto it=compress.begin();it!=compress.end();it++)
    {
        it->second=counter++;
    }

    vector<vector<ll>>v(counter);//stores the relative end time for all the movies starting at relative time i at index i;
    for(ll i=0;i<n;i++)
    {
        v[compress[a[i]]].push_back(compress[b[i]]);
    }
    ll res=0;
    bool watching =false;
    ll currMovieStartTime=0;
    ll currMovieEndTime=0;
    for(ll i=0;i<counter;i++)
    {   
        if(i==currMovieEndTime and watching)
        {
            res++;
            watching=false;
        }
        ll shortestMovieStartingNowEndTime=INT_MAX;
        for(auto x:v[i])
        {
            shortestMovieStartingNowEndTime=min(shortestMovieStartingNowEndTime,x);
        }
        if(!watching)
        {   
            if(shortestMovieStartingNowEndTime!=INT_MAX)
            {
                currMovieStartTime=i;
                currMovieEndTime=shortestMovieStartingNowEndTime;
                watching=true;
            }
            continue;
        }
        if(shortestMovieStartingNowEndTime<currMovieEndTime)
        {
            currMovieEndTime=shortestMovieStartingNowEndTime;
            currMovieStartTime=i;
        }
    }
    cout<<res;
    return 0;
}

/*
Another easier way to do it is to simply sort the pairs in increasing order of ending times. 
Then for each pair, if the starting time>=current time then choose it and set current time as the ending time 
of that movie. also since we are also going to get increasing order of strting time, if the starting time is 
smaller than the current time, we just iterate to next pair.
This is similar to the most trains we can catch problem given their arriving and departure time
*/