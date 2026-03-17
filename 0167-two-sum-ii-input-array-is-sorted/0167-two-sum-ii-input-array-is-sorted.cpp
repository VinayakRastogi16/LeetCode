class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i = 0, j = arr.size()-1;
        vector<int> ans;
        int currSum = 0;

        while(i<j){
            currSum = arr[i]+arr[j];
            if(currSum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;

            } else if(currSum > target){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
