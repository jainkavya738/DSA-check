class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, int> m;
        for(int a : nums) m[a]++;

        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = m[nums[i]], val = nums[i];
            bool check = true; int j = i;

            while(temp && j < nums.size()){
                if(nums[j] != val){
                    check = false;
                    break;
                }

                j++; temp--;
            }
 
            if(check && temp == 0){
                count++;
                i = (j - 1);
            }
        }

        return count;
    }
};