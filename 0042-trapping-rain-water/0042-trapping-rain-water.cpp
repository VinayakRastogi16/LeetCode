class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        leftMax[0] = height[0];
        rightMax[height.size()-1] = height[height.size()-1];

        for(int i=1; i<height.size();i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
            
        }

        for(int i = height.size()-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        int waterTrapped = 0;

        for(int i = 0; i<height.size(); i++){
            int currWater = min(leftMax[i], rightMax[i]) - height[i];
            if(currWater>0){
                waterTrapped += currWater;
            }
        }
        
        return waterTrapped;
    }
};