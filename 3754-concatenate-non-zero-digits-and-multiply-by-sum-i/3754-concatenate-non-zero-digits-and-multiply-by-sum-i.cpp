class Solution {
public:

    long long sumAndMultiply(int n) {
        vector<long long> digits;

        while (n > 0) {
            long long d = n % 10;
            if (d != 0)
                digits.push_back(d);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        long long x = 0;
        long long sum = 0;

        for (int d : digits) {
            x = x * 10 + d;
            sum += d;
        }

        return x * sum;
    }
};