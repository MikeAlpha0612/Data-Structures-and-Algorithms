class Solution {
public:
    // FIX: Pass strings by constant reference to avoid costly copies
    int result( string& text1,  string& text2, int n1, int n2, vector<vector<int>>& dp) {
        
       for(int i = 0; i <= n2; i++){
        dp[0][n2] = 0 ;
       }
      
       for(int i = 0; i <= n1; i++){
        dp[n1][0] = 0 ;
       }

       for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){

            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

      
       }
         return dp[n1][n2];

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        // DP table size is good for 0 to n-1 indexing
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

         for(int i = 0; i <= n2; i++){
        dp[0][n2] = 0 ;
       }
      
       for(int i = 0; i <= n1; i++){
        dp[n1][0] = 0 ;
       }

       for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){

            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

      
       }
         return dp[n1][n2];
        
    }
};