class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }

        vector<int> dp(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            dp[nums[i]]+=nums[i];
        }
        
        for(int i=2;i<dp.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
        }
        return dp[maxi];
    }
};
