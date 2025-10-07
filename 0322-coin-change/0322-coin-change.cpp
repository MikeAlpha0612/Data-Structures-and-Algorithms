class Solution {
public: 
    
    int result(vector<int>& coins, int amount, vector<vector<int>>&dp, int n){
          
         if(dp[n][amount] != -1){
            return dp[n][amount];
         }

          if(amount == 0){
            return 0;
          }

          if(n == 0){
            if(amount % coins[n] == 0){
                return amount/coins[n];
            }else{
                return 1e8;
            }
          }

          if( n < 0 || amount < 0){
            return 1e8;
          }


          int notTaken = result(coins, amount, dp, n-1);
          int Taken = 1e8;

          if(amount >= coins[n]){
            Taken = 1 + result(coins, amount - coins[n], dp, n);
          }

          return dp[n][amount] = min(Taken,notTaken);
    }

    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
         int count = 0;

         vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

         int res = result(coins, amount, dp, n-1 );

         

         if(res < 1e8){
            return res;
         }

         return -1;
    }

};