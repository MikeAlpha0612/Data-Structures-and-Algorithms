class Solution {
public:

    int result(vector<int>& nums,int ind, int n, int prev_index, vector<vector<int>>& dp){
         
         if(ind == n){
            return 0;
         }

         if(dp[ind][prev_index+1] != -1){
            return dp[ind][prev_index+1];
         }

         int notTake = result(nums, ind+1, n, prev_index, dp);

         int Take = 0;

         if(prev_index == -1 || nums[ind] > nums[prev_index]){
            Take = 1 + result(nums, ind+1, n, ind, dp);
         }

         return dp[ind][prev_index+1] = max(Take, notTake) ;


    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev_index = -1;
        vector<vector<int>>dp(n+1, vector<int>(n + 1, -1));

        int res = result(nums, 0, n, prev_index, dp);

        return res;



    }
};