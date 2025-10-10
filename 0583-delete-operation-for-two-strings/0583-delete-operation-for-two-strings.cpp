class Solution {
public:

    int result(string& word1, string& word2, int n1, int n2, vector<vector<int>>&dp ){

        if(n1 < 0 || n2 < 0){
            return 0;
        }

        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }

        if(word1[n1] == word2[n2]){
            return dp[n1][n2] = 1+ result(word1, word2, n1-1, n2-1, dp);
        }

        return dp[n1][n2] = max(result(word1, word2, n1-1, n2, dp), result(word1, word2, n1, n2-1, dp));

    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));

        int res = result(word1, word2, n1-1, n2-1, dp);

        return n1- res + n2 - res;
    }
};