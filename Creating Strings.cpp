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
 
void generate(string str,int n,set<string>&s)
{   
    //n is first unfixed position
    if(n==str.length())
    {
        s.insert(str);
        return;
    }
    
    for(int i=n;i<str.length();i++)
    {   
        if(str[i]==str[n] and i!=n) continue;
        char temp=str[n];
        str[n]=str[i];
        str[i]=temp;
        generate(str,n+1,s);
    }
}
 
void solve()
{
    string str;
    cin>>str;
    set<string>s;
    generate(str,0,s);
    cout<<s.size()<<"\n";
    for(string str:s)
    {
        cout<<str<<"\n";
    }
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {   
        solve();
    }
    return 0;
}