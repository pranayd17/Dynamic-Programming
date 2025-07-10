const int mod = 1e9+7;

int helper(int a,int b,bool first,vector<vector<int>>& dp)

{

    if(a==1&&b>9)

        return 0;

    if(a==1&&b>=0&&b<=9)

        return 1;

    if(dp[a][b]!=-1)

        return dp[a][b];

    int ans=0;

    for(int i=0;i<=9;i++)

    {

        if(first==false)

        {

            first=true;

            continue;

        }

        if(i<=b)

        ans = (ans%mod + helper(a-1,b-i,first,dp)%mod)%mod;

    }

    return dp[a][b] = ans;

}

int Solution::solve(int a, int b) {

    if(9*a<b)

        return 0;

    vector<vector<int>> dp(a+1,vector<int>(b+1,-1));

    return helper(a,b,false,dp);

}
