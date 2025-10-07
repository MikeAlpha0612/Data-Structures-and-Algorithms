class Solution {
public:

    int result(int n, int amount, vector<int>& coins, vector<vector<int>>& dp){

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        if(n == 0){
            if(amount % coins[n] == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(amount == 0){
            return 1;
        }

        int notTaken = result(n-1, amount, coins, dp);
        int Taken = 0;
        if(amount >= coins[n]){
            Taken = result(n, amount-coins[n], coins, dp);
        }

        return dp[n][amount] = Taken + notTaken;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1));

        int res = result(n-1, amount, coins, dp);

        return res;
    }
};