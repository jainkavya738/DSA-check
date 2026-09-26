class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for(int a: nums) xr ^= a;

        //we want the bit where x, y (single nos.) will differ
        //This will be the bit where (x ^ y)'s bit will be equal to 1
        //Vo jaha bhi 1 ho rha h usme se koi bhi ek bit lelo

        int bit = (xr) & (-xr);  
        //We will take the rightmost bit.... because it is very easy to calculate
        
        //Using that bit, divide the nums in different groups.... both x and y will go in different groups as they differ at that bit
        //And as other numbers are twice in occurence.... they will cancel out each other in a single group

        long long xr1 = 0, xr0 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & bit) xr1 ^= nums[i];
            else xr0 ^= nums[i];
        }

        return {(int)xr0, (int)xr1};
    }
};