class Solution {
public:

    bool result(int ind, int target, vector<vector<int>>& dp, vector<int>& nums ){

        if(dp[ind][target] != -1){
            return dp[ind][target];
        }

        if(target == 0){
            return true;
        }

        if(ind == 0){
            return target == nums[ind];
        }

    

        bool notTaken = result(ind-1, target, dp, nums);
        bool taken = false;

        if(nums[ind] <= target){
            taken = result(ind-1, target-nums[ind], dp, nums);
        }

        return dp[ind][target] = taken || notTaken;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for( auto it : nums){
            sum += it;
        }

        int target;

        if(sum % 2 == 1) {
            return false;
        }else{
            target = sum/2;
        }

        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));

        bool res = result(n-1, target, dp, nums);

        return res;






    }
};