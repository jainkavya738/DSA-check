class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

       for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) isPrime[i] = false;
            }
        }

        long long sum = 0, sumPrime = 0;
        for(int i = 0; i < nums.size(); i++){
            if(isPrime[i]) sumPrime += nums[i];
            else sum += nums[i];
        }

        return abs(sum - sumPrime);
    }
};