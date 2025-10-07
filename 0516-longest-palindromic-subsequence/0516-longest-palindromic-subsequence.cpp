class Solution {
public:

    int result (int n1, int n2, string& s1, string& s2, vector<vector<int>>&dp){

        if(n1 < 0 || n2 < 0){
            return 0;
        }

        if(dp[n1][n2] != -1){
            return dp[n1][n2] ;
        }

        if(s1[n1] == s2[n2]){
            return dp[n1][n2] = 1 + result(n1-1, n2-1, s1, s2, dp);
        }

        return dp[n1][n2] = max(result(n1-1, n2, s1, s2, dp), result(n1, n2-1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        
        string str;
        int n= s.size();

        for(int i = 0; i < n; i++){
            str = s[i] + str;
        }

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        int res = result(n-1, n-1, s, str, dp);

        return res;


    }
};