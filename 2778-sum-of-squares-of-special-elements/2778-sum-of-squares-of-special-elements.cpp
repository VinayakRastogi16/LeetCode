class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i*i<=n; i++){
            if(n%i==0){
                ans += (nums[i-1]*nums[i-1]);

                int other = n/i;

                if(other!=i){
                    ans+=nums[other-1]*nums[other-1];
                }
            }
        }

        return ans;
    }
};