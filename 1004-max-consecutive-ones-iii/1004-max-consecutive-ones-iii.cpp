class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0; int n = nums.size(); int temp = k; int ans = 0;
        while(i < n && j < n){
            if(nums[j] == 1){
                j++;
                ans = max(ans, (j - i));
            }
            else{
                if(temp > 0){
                    temp--;
                    j++;
                    ans = max(ans, (j - i));
                } else{
                    ans = max(ans, (j - i));

                    while(i < n && nums[i] != 0) i++;
                    i++;

                    temp = 1;
                }
            }
        }

        return ans;
    }
};