class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0, count = 0, sum = 0;
        while(r < nums.size()){
            sum += nums[r];

            while(l <= r && sum > goal){
                sum -= nums[l];
                l++;
            }

            if(sum == goal){
                if(goal == 0) count += (r - l + 1);
                else{
                    int temp = l;
                    while(temp <= r && nums[temp] == 0) temp++;

                    count += (temp - l + 1);
                }
            }

            r++;
        }

        return count;
    }
};