class Solution {
public:
    // bool res=0;
    bool f(int i,int t,vector<int> &arr, vector<vector<int>> &dp){
        if(i==arr.size()) return 0;
        if(t==0) {
            // res=1;
            return 1;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        bool not_take=dp[i][t]=f(i+1,t,arr,dp);
        bool take=false;
        if(arr[i]<=t){
            take=f(i+1,t-arr[i],arr,dp);
        }
        return dp[i][t]=take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++) s+=nums[i];
        if(s%2) return 0;
        vector<vector<int>> dp(n+1,vector<int> (s/2+1,-1));
        return f(0,s/2,nums,dp);
    }
};
