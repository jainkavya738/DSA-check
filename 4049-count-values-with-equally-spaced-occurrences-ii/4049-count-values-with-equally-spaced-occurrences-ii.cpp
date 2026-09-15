class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> a;
        for(int i = 0; i < nums.size(); i++) a[nums[i]].push_back(i);

        int count = 0;
        for(auto& p : a){
            const vector<int> indices = p.second;
            if(indices.size() >= 3){
                bool check = true;
                for(int i = 1; i < indices.size() - 1; i++){
                    if((indices[i] - indices[i-1]) != (indices[i+1] - indices[i])){
                        check = false;
                        break;
                    }
                }

                if(check) count++;
            }
        }

        return count;
    }
};