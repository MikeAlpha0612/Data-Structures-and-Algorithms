class Solution {
public:

    void result(vector<int>& nums, int n, int& sum){

        if(n == 1){
            sum = nums[0];
            return;
        }

        for(int i = 0; i < n-1; i++){
          nums[i] = (nums[i] + nums[i+1])%10;
          
        }

        nums.pop_back();
        result(nums, n-1, sum);
        
    }

    int triangularSum(vector<int>& nums) {
        
        int n = nums.size();

        int sum = 0;

        result(nums, n, sum);

        return sum;

        
      
    }
};