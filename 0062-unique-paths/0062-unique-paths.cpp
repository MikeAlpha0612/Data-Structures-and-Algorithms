class Solution {
public:

    int result(int m, int n, vector<vector<int>>&dp){
        if(m < 0 || n < 0){
            return 0;
        }

        if(m ==0 && n == 0){
            return 1;
        }

        if(dp[m][n] != -1){
            return dp[m][n] ;
        }

        int goTop = result(m-1,n, dp);
        int goLeft = result(m, n-1,dp);

        return dp[m][n] = goTop + goLeft;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));

        int res = result(m-1, n-1, dp);

        return res;

    }
};