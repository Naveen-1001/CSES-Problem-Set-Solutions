#include
vector<vector<int>>dp(nums.size(),vector<int>(x+1,0));

for(int i=0;i<nums.size();i++)
{
    dp[i][0]=1;
}

for(int i=1;i<=x;i++)
{
    for(int j=0;j<nums.size();j++)
    {   
        if(i>=nums[j])
        {
            dp[j][i]=(dp[j][i]+dp[j][i-nums[j]])%modc;
        }
        if(j>0)
        {
            dp[j][i]=(dp[j][i]+dp[j-1][i])%modc;
        }
    }
}

return dp[nums.size()-1][x];