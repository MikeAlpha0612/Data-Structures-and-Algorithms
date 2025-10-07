class Solution {
public:
    
    int result(int n, vector<int>&dp){
        if(n == 0 || n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int stepOne = result(n-1,dp);
        int stepTwo = 0;
        if(n > 1){
            stepTwo = result(n-2, dp);
        }

        return dp[n] = stepOne + stepTwo ;
    }

    int climbStairs(int n) {
        
        if(n == 0){
            return 1;
        }
        
        vector<int>dp(n+1,-1);

        int res = result(n, dp);

        return res;

    }
};