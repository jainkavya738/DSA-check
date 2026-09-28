class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign  = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;

        long long n = dividend, d = divisor;

        if (n < 0) n = -n;
        if (d < 0) d = -d;

        long long ans = 0;
        while(n >= d){
            int count = 0;
            while(count < 31 && n >= (d << (count + 1))) count++;

            ans += (1LL << count);
            n -= (d << count);
        }

        if(ans > INT_MAX && sign == true) return INT_MAX;
        else if(ans >= 2147483648LL && sign == false) return INT_MIN;

        return sign? (int)ans: (-(int)ans);
    }
};