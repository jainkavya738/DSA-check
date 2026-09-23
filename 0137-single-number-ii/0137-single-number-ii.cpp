class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ans = 0;
//         for(int bitIdx = 0; bitIdx < 32; bitIdx++){
//             int count1 = 0;
//             for(int i = 0; i < nums.size(); i++){
//                 if(nums[i] & (1 << bitIdx)) count1++;
//             }

//             if(count1%3 == 1) ans |= (1 << bitIdx);
//         }

//         return ans;
//     }
// };