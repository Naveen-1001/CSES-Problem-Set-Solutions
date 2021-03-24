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
 
void generate_next_masks(int current_mask,int i,int next_mask,int n,vector<int>&next_masks)
{   
    //Created a complete column of next mask. 
    if(i==n+1)
    {
        next_masks.push_back(next_mask);
        return;
    }
 
    //Case-1//Current_mask has ith bit set. i.e for current mask of this col, we placed tile horizontally(in direction of inc. col).
    //So now, for the next_mask, this bit cannot be 1.
    if((current_mask & (1<<i))!=0)
    {
        generate_next_masks(current_mask,i+1,next_mask,n,next_masks);
    }
 
    //Case-3//Ith and (i+1)th bit set in curr_mask. So we have option of placing vertically in next mask. Cannot do so if either one of the bits were set.
    //So have to check separately than the 
    if(i!=n)
    {
        if((current_mask & (1<<i))==0 and (current_mask & (1<<(i+1)))==0)
        {
            generate_next_masks(current_mask,i+2,next_mask,n,next_masks);
        }
    }
 
    //Case-2//Current_mask ith bit is 0 i.e tile placed vertically, i.e in next_mask, tile can be pplace horizontally.
    if((current_mask & (1<<i))==0)
    {
        generate_next_masks(current_mask,i+1,next_mask+(1<<i),n,next_masks);
    }
}
 
//here size of column=n elements. 
 
int dp[1001][1<<11];
//solve(col,mask,m,n) gives number of solutions for column col to col m when col has a current_mask=mask
int solve(int col,int mask,const int m,const int n)
{   
    //mask gives the number of tiles whcih are already filled due to the previous column
    if(col==m+1)
    {
        if(!mask)return 1;// in last column, no tiles whould be of height 2. So m+1th column will always have mask=0
        else return 0;
    }
 
    if(dp[col][mask]!=-1)
    {
        return dp[col][mask];
    }
 
    int answer=0;
    vector<int> next_masks;
    generate_next_masks(mask,1,0,n,next_masks);
 
    for(int next_mask: next_masks)
    {
        answer=(answer+solve(col+1,next_mask,m,n))%modc;
    }
 
    return dp[col][mask]=answer;
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
        int n,m;
        cin>>n>>m;
        memset(dp,-1,sizeof dp);
        cout<<solve(1,0,m,n);
    }
    //cout<<"\n"<<(1<<11);
    return 0;
}

/*
Bottom up way of doing it

Here the jth bit of mask is zero means that jth position is filled

int n, m;
vector < vector<long long> > dp;


void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    if (x == n)
        return;
    if (y >= m)
        dp[x+1][next_mask] += dp[x][mask];
    else
    {
        int my_mask = 1 << y;
        if (mask & my_mask)
            calc (x, y+1, mask, next_mask);//if current bit is empty, we place a 1*2 bit in current row. So that also extends to next row. So that bit remains zero and we check other configurations by doing y+1.
        else
        {
            calc (x, y+1, mask, next_mask | my_mask); //If the curent bit is already filled, either due to 1*2 bit of prev row or 2*1 of current row(added due to prev config), we check if we can add 2*1 in next row(this is when next bit is also filled from curr row or below.). Ieven if the next j+1th is empty or not, we can still keep the jth bit in next row empty
            if (y+1 < m && ! (mask & my_mask) && ! (mask & (my_mask << 1)))//Implies that if both of the jth ad j+1th bit are zero(either they are 1*2 or 2 2*1 blocks,), then we can place a 1*2 in the next row. Both of these will be covered individually
                calc (x, y+2, mask, next_mask);
        }
    }
}


* also when we are checking a current row taking ref from prev row and adding tiles extending to next row, we do not have any 


So to sum it up, at each position of the grid, if the curr tile is empty, we add a tile extending to next row and recurse to next bit of same row.
If the curr bit is already filled(due to prev row) we can either leave the bit above this in the next row empty and recurse to next tile in curr row or
, we can also check if the next bit is full. If yes, we can add a tile entirely in above row above jth and j+1th bit in curr row.
Here the j+1th bit will never be in a state extending to next row before we check for this. This can only happen when the j+1th bit
is empty and we add a tile extending to next row and that happens when we recurse to j+1th tile
int main()
{
    cin >> n >> m;

    dp.resize (n+1, vector<long long> (1<<m));
    dp[0][0] = 1;
    for (int x=0; x<n; ++x)
        for (int mask=0; mask<(1<<m); ++mask)
            calc (x, 0, mask, 0);

    cout << dp[n][0];

}

*/
