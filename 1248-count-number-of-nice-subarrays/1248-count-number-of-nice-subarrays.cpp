class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, countOdd = 0, ans = 0;
        while(r < nums.size()){
            if(nums[r] & 1){
                countOdd++;

                if(countOdd > k){
                    while(l < r && nums[l]%2 == 0) l++;

                    if(l < r) l++;
                    countOdd--;
                }

                if(countOdd == k){
                    int leftValid = 1, rightValid = 1, temp1 = l;
                    while(temp1 < r && nums[temp1]%2 == 0){
                        temp1++;
                        leftValid++;
                    }

                    int temp = (r + 1);
                    while(temp < nums.size() && nums[temp]%2 == 0){
                        temp++;
                        rightValid++;
                    }

                    ans += (leftValid * rightValid);
                }
            }
            
            r++;
        }

        return ans;
    }
};