class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp = n;
        int digit = 1;
        while(temp != 0){
            digit *= temp%10;
            temp /= 10;
        }

        if(digit%t == 0){
            return n;
        }
        n++;
        }
    }
};