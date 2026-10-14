class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if(sum>num*9){
            return "";
        }

        int tot9 = sum/9;
        int remain = sum%9;

        string ans(tot9, '9');

        if(remain>0){
            ans.push_back(remain+'0');
        }

        ans.append(num - ans.length(), '0');

        return ans;
    }
};