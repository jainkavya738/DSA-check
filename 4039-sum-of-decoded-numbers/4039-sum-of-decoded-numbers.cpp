class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp){
        long long res = 1;
        while(exp){
            if(exp & 1) res = (res * base)%MOD;
            base = (base * base)%MOD;
            exp >>= 1;
        }

        return res%MOD;
    }

    long long sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        for(long long i = 0; i < nums.size(); i++){
            long long width = nums[i]%10, d = nums[i]/10;
            long long temp = d, x = 0;

            vector<long long> digits;
            
            if(d == 0) digits.push_back(0);
            
            while(temp){
                long long dig = temp%10;
                digits.push_back(dig);
                temp /= 10;
            }

            if(width > digits.size()) continue;

            long long j = digits.size() - 1;
            while(width > 0){
                x = (x * 10) + digits[j];
                j--;
                width--;
            }
            
            long long y = 0;
            while(j >= 0){
                y = (y * 10) + digits[j];
                j--;
            }
            
            sum = (sum + power(x, y)) % MOD;
        }

        return (long long)sum;
    }
};