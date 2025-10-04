class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, res = 0, oddCount = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 == 1) oddCount++;
            while (oddCount > k) {
                if (nums[l] % 2 == 1) oddCount--;
                l++;
            }
            res += (r - l + 1); // all subarrays ending at r
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
