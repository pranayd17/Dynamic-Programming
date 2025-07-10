int dp[505][505];

int func(vector<int> &nums , int l , int r )
{
    if(l>r)
    {
        return 0;
    }
   
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
   
    int cost1 = max (nums[l] - func(nums , l+1 , r) , nums[r] - func(nums , l , r-1));
   
    return dp[l][r]=cost1;
}

int Solution::maxcoin(vector<int> &nums) {
   
    int n=nums.size();
   
    memset( dp , -1 , sizeof(dp));
   
    int val = func(nums , 0 , n-1);
   
    int sum=0;
   
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
   
    int res = (val + sum )/2; // we have calculated My profit - Other player profit by above memoization
   
    // so my pofit will be  int res = (val + sum )/2
   
    return res;
   
   
}
