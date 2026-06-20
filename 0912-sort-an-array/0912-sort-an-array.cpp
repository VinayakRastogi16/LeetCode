class Solution {
public:


    void merge(vector<int>& nums, int st, int end, int mid){
        vector<int> temp;
        int i = st;

        int j = mid+1;

        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);

            }
        }

        while(i<=mid){
            temp.push_back(nums[i++]);
        }

        while (j<=end)
        {
        temp.push_back(nums[j++]);
        }

        for (int idx = st, x=0; idx <= end; idx++)
        {       
        nums[idx] = temp[x++];
        }
    }

    void mergeSort(vector<int>& nums, int st, int end){

        if(st>=end){
            return;
        }

        int mid = st+(end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, st, end, mid);


    }
    

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0,  nums.size()-1);
        return nums;
    
    }

};