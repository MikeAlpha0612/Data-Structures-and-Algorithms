class Solution {
public: 
    
    int result(vector<int>& nums, int goal, int n){
        // THE FIX: Handle the edge case where goal becomes negative.
        if (goal < 0) {
            return 0;
        }

        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;

        while(r < n){
            sum += nums[r];

            while( sum > goal){
             sum-= nums[l];
             l++;
            }
            
            count += (r-l+1);

            r++;

        }
        return count;

    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int res = result(nums, goal, n) - result(nums, goal-1, n);

        return res;
            
    
    }
};