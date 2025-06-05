class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long int sum1 = 0;
        for(auto &i: nums){
            sum1 += i;
        }
        if(sum1 < 2*1LL*k || nums.size()<=1)return 0;
        int n = nums.size(),i,j;
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(k,-1));
        for(i = 0; i <= n; i++){
            for(j = 0; j < k; j++){
                if(i==0){
                    dp[i][j] = 0;
                }if(j==0){
                    dp[i][j] = 1;
                }
                if(i && j){
                    if(j>=nums[i-1]){
                        dp[i][j] = (dp[i-1][j]*1LL+dp[i-1][j-nums[i-1]])%mod;
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        // cout<<"#";
        int sum = 0, total = 1,a=2;
        for(auto &i : dp[n]){
            sum = (sum+i)%mod;
        }
        sum = (sum*1LL*2)%mod;
        // cout<<"#\n";
        while(n){
            if(n&1){
                total = (total*1LL*a)%mod;
            }
            a = (a*1LL*a)%mod;
            n >>= 1;
        }
        return ((total-sum)%mod+mod)%mod;
    }
};
