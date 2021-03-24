#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll fast_power(ll a, ll b, ll m)//a^b
{
    if(b==0) return 1;
    if(b==1) return a;

    ll temp=fast_power(a,b/2,m);

    if(b%2==0) return (temp*temp)%m;
    return ((temp*temp)%m*a)%m;
}

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b); 
}

ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

ll sum_of_digits(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{   
    vector<ll>positionOfPowersOf10(19);
    positionOfPowersOf10[0]=1;
    ll curr_power=10;
    ll prevpower=1;
    for(int i=1;i<=18;i++)
    {
        positionOfPowersOf10[i]=positionOfPowersOf10[i-1]+(curr_power-prevpower)*(i);
        prevpower*=10;
        curr_power*=10;
    }
    /*
    for(ll i=0;i<=18;i++)
    {
        cout<<positionOfPowersOf10[i]<<" ";
    }
    cout<<"\n";
    */
    int t;
    cin>>t;
    while(t--)
    {   
        ll n;
        cin>>n;
        vector<ll>::iterator it=upper_bound(positionOfPowersOf10.begin(),positionOfPowersOf10.end(),n);
        ll pos=it-positionOfPowersOf10.begin();
        it--;
        ll div=(n-*it)/pos;
        ll rem=(n-*it)%pos;
        ll sub=1;
        for(ll j=0;j<pos-1;j++)
        {
            sub*=10;
        }
        ll number=sub+div;
        //cout<<"Number is: "<<number<<" ";
        ll noOfModulo=pos-rem;
        for(int i=0;i<noOfModulo-1;i++)
        {
            number/=10;
        }
        int res=number%10;
        cout<<res<<"\n";
    }
    return 0;
}