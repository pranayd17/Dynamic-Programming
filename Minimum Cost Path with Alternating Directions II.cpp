#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    ll f(int i,int j,int m,int n,vector<vector<int>>& waitCost,int t){
        if(i==m-1 && j==n-1) return (ll)m*n;
        if(i>m-1 || j>n-1) return LLONG_MAX;
        
        if (dp[i][j][t%2]!=-1) return dp[i][j][t%2];
        
        ll ans;
        if (t%2==0) {
            ans=f(i,j,m,n,waitCost,t+1) + waitCost[i][j];
        } else {
            ans=(ll)(i+1)*(j+1)+min(f(i,j+1,m,n,waitCost,t+1),f(i+1,j,m,n,waitCost,t+1));
        }

        return dp[i][j][t%2]=ans;
    }
    
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        dp.clear();
        dp.resize(m+1,vector<vector<ll>>(n+1,vector<ll>(2,-1)));
       return f(0,0,m,n,waitCost,1); 
    }
};
