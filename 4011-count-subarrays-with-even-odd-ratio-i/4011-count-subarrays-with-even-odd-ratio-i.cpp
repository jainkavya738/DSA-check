class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        int oriNum = a, oriDeno = b, count = 0;
        for(int i = 0; i < n; i++){
            int countOdd = 0, countEven = 0;
            for(int j = i; j < n; j++){
                if(nums[j] & 1) countOdd++;
                else countEven++;

                if(countOdd > 0){
                    int tempNum = countEven;
                    int tempDeno = countOdd;

                    if((oriNum * tempDeno) >= (oriDeno * tempNum)) count++;
                }
            }
        }

        return count;
    }
};