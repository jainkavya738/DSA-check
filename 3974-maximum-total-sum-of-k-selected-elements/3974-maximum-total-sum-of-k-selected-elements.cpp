class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());

        long long sum = 0;
        for(int i = 0; i < k; i++){
            if(mul >= 1) sum += (1LL * mul * nums[i]);
            else sum += nums[i];

            mul--;
        }

        return sum;
    }
};