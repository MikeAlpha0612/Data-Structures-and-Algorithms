class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
       
        int maxi = 0;

        for(int i = 0; i < n; i++){
            int count = 0;
            unordered_map<char,int>mpp;
            for(int j = i; j < n; j++){
               
               if(mpp.find(s[j]) == mpp.end()){
                   mpp[s[j]]++  ;
                   count++;
               }else{
                break;
               }

               maxi = max(maxi,count);
            }
        }

        return maxi;
    }
};