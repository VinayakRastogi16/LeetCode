class Solution {
public:
    int reverse(int x) {
    long long n=x;
    long long temp = 0;
    while(n!=0){
        temp = (temp*10)+n%10;
        n /= 10;
    }

    n =temp;
    if(n < INT_MIN || n > INT_MAX)
        return 0;
    return (int)n;
    }
};