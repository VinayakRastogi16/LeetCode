class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        while(temp){
            sum += temp%10;
            prod *= temp%10;
            temp /= 10;
        }
        int tot = sum+prod;
        return n%tot==0;

    }
};