class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num : nums) result ^= num;  

        //sabka XOR le lenge toh repeating numbers toh kat jayenge but but jo single number hai vo rhe jaayega

        return result;
    }
};