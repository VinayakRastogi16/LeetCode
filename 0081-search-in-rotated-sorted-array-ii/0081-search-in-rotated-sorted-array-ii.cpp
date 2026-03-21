class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int si = 0;
        int ei = arr.size()-1;

        while(si<=ei){
            int mid = si + (ei - si) / 2;

            if (arr[mid] == target)
            {
                return true;
            }

            if(arr[si]==arr[mid] && arr[mid]== arr[ei]){
                si++;
                ei--;
            }else if (arr[si]<=arr[mid]){
                    if (arr[si]<= target && target<arr[mid]){
                        ei = mid-1;
                    }else{
                        si = mid+1;
                    }
                }else{
                    if (arr[mid]<target && target <= arr[ei]){
                    si = mid+1;
                }else{
                    ei = mid-1;
                }
                
            }
        }

        return false;
    }
};