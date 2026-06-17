class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int can ;
        for(int i = 0; i< nums.size(); i++){
            if(count == 0){
                count = 1;
                can = nums[i];
            }else if(nums[i] == can){
                count++;
            }else{
                count --;
            }
        }

        int cnt1 = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]==can) cnt1++;
        }

        if(cnt1>(nums.size()/2)){
            return can;
        }

        return -1;

    }
};