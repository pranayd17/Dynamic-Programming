class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long p = 1e9 + 7;
        vector<vector<long>> dp(n+1, vector<long>(6, 0));
        vector<long> sum(n+1, 0);
        sum[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 6; ++j)  {
                for (int k = 1; k <= rollMax[j] && i - k >= 0; ++k)
                    dp[i][j] = (dp[i][j] + sum[i-k] - dp[i-k][j] + p) % p;
                sum[i] = (sum[i] + dp[i][j]) % p;
            }                
        }
        
        return sum[n];
    }
};
