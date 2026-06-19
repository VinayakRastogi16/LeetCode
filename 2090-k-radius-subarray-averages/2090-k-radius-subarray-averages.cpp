class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avg(n, -1);

        int window = 2*k + 1;

        if(window>n){
            return avg;
        }

        long long windowSum = 0;

        for(int i = 0; i< window; i++){
            windowSum += nums[i];

        }

        avg[k] = windowSum/window;

        for(int i= window; i< n; i++){
            windowSum += nums[i];
            windowSum -= nums[i-window];

            int center = i - k;
            avg[center] = windowSum/window;
        }

        return avg;
    }
};