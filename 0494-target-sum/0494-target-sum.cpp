class Solution {
public:
    
    int result(vector<int>& nums, int target, int n, vector<vector<int>>& dp){
         
         

        if( n < 0){
            return (target == 0) ? 1 : 0;
        }

         if(dp[n][target] != -1){
            return dp[n][target];
         }

         int Taken = 0;

         if(target >= nums[n]){
            Taken = result(nums, target - nums[n], n-1, dp);
         }

         int notTaken = result(nums, target, n-1, dp);

         return dp[n][target] = Taken + notTaken;

    }
  
    int findTargetSumWays(vector<int>& nums, int target) {
       
      int n = nums.size();
      int sum = 0 ;

      for(auto it : nums){
          sum += it;
      }

      if(target + sum < 0){
        return 0;
      }

      if((target + sum )% 2 != 0){
        return 0;
      }

      vector<vector<int>>dp(n+1, vector<int>(((target + sum)/2)+1, -1));

    int res = result(nums, (target + sum)/2, n -1, dp);

    return res;
       
    }
};