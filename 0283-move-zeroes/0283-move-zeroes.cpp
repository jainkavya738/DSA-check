class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int n = nums.size(); int count = 0;
    //     for(int i = 0; i < n; i++){
    //         int temp = i;
    //         if(nums[temp] == 0){
    //             nums.erase(nums.begin() + temp);
    //             count++;
    //         }
    //     }

    //     while(count--) nums.push_back(0);
    // }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size(); int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};