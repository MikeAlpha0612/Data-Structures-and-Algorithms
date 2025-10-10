class Solution {
public:



    int result(vector<int>& energy, int k, int ind , int n, vector<int>& dp){

        if( ind >= n){
            return 0;
        }
     
        
        
        if(dp[ind] != -1){
            return dp[ind];
        }

        int maxi =  energy[ind] + result(energy, k, ind+k, n, dp);
     
        return dp[ind] = maxi;;


    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int>dp(n+1, -1);
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
           maxi = max(maxi, result(energy, k, i, n, dp));
        }

        return maxi ;


    }
};