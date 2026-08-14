class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pos;
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0) pos.push_back(nums[i]);
        }

        if(pos.empty()) return nums;
        
        k = k%pos.size();

        rotate(pos.begin(), pos.begin() + k, pos.end());
        
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0) nums[i] = pos[idx++];
        }

        return nums;
    }
};