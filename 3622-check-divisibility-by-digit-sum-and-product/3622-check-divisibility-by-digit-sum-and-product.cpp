class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n, sumDigit = 0, prodDigit = 1;
        while(temp){
            int dig = temp%10;
            sumDigit += dig;
            prodDigit *= dig;
            temp /= 10;
        }

        return (n % (sumDigit + prodDigit) == 0)? true : false;
    }
};