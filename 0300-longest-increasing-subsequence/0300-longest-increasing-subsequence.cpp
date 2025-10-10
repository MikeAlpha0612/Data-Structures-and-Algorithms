class Solution {
public:

  
  

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>arr;

        arr.push_back(nums[0]);
        int len = 1;

        for(int i = 1; i < n ; i++){

              if(nums[i] > arr.back()){
                arr.push_back(nums[i]);
                len++;
              }else{
                 auto it = lower_bound(arr.begin(), arr.end(), nums[i] );
                 *it  = nums[i];
              }
       }

       return len;



    }
};