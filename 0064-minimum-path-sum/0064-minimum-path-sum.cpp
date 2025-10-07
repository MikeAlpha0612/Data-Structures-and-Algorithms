class Solution {
public:
    
    int result(int m, int n, vector<vector<int>>&dp, vector<vector<int>>& grid ){

        if(m == 0 && n == 0){
            return grid[m][n] ;
        }

        if(m < 0 ||  n < 0){
            return 1e8 ;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int GoToTop = grid[m][n] + result(m-1,n, dp, grid);
        int GoToLeft = grid[m][n] + result(m, n-1, dp, grid);

        return dp[m][n] = min(GoToTop, GoToLeft);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n,-1));

        int res = result(m-1, n-1, dp, grid);

        return res;


    }
};