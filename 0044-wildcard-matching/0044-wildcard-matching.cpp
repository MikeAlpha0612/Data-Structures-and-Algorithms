class Solution {
public:

   bool result(string& s, string& p, int n1, int n2, vector<vector<int>>& dp){

        if(n1 < 0 && n2 < 0){
        return true;
       }
      
       if(n2 < 0 && n1 >= 0){
        return false;
       }

       if(n1 < 0 && n2 >= 0){
        for(int i = 0; i <= n2; i++){
            if(p[i] != '*'){
                return false;
            }
        }
        return true;
       }

       if(dp[n1][n2] != -1){
         return dp[n1][n2];
       }

    

       if(s[n1] == p[n2] || p[n2] == '?'){
        return dp[n1][n2] = result(s,p, n1-1,n2-1, dp);
       }

       if(p[n2] == '*'){
         return dp[n1][n2] = result(s,p, n1, n2-1, dp) || result(s,p, n1-1, n2, dp);
       }

    
    
    return false; ;

   }


    bool isMatch(string s, string p) {
         int n1 = s.size();
         int n2 = p.size();

         vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1)) ;

         bool res = result(s,p,n1-1,n2-1,dp);

         return res;




    }
};