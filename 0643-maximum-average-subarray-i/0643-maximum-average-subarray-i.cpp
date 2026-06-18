class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long currSum = 0;

        for(int i = 0; i< k; i++){
            currSum += nums[i];
        }

        long long maxSum = currSum;

        for(int i = k; i<nums.size(); i++){
            currSum += nums[i];
            currSum -= nums[i-k];

            maxSum = max(maxSum, currSum);
        }

        return (double)maxSum/k;
    }
};