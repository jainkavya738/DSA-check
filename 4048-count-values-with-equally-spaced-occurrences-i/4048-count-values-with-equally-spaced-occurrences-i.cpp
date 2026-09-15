class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> a;
        for(int i = 0; i < nums.size(); i++){
            a[nums[i]].push_back(i);
        }

        int count = 0;
        for(auto& p : a){
            int i = p.first;
            if(p.second.size() == 3 && ((a[i][1] - a[i][0]) == (a[i][2] - a[i][1]))) count++;
        }

        return count;
    }
};