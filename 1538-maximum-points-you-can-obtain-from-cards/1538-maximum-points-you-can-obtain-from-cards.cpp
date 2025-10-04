class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;

        for(int i = 0; i < k; i++){
            maxSum += cardPoints[i];
        }

        int sum = maxSum;

        int r = cardPoints.size()-1;
        int l = k-1;

        while(k--){
            sum = sum-cardPoints[l];
            l--;
            sum += cardPoints[r];
            r--;

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};