class Solution {
public:

    int result(vector<int>& nums, int n, vector<int>& dp){
       if(n == 0){
        return nums[n];
       }

       if( n < 0){
        return 0;
       }

       if(dp[n] != -1){
        return dp[n];
       }

       int chooseToSteal = nums[n] + result(nums, n-2, dp);

       int notChooseToSteal = result(nums, n-1,dp);

       return dp[n] = max(chooseToSteal, notChooseToSteal);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,-1);

        int res = result(nums, n-1, dp);

        return res;

    }
};