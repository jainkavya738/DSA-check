class Solution {
public:
    int countDigits(int num) {
        int temp = num, count = 0;
        while(temp){
            int dig = temp%10;
            if(num%dig == 0) count++;
            temp /= 10;
        }

        return count;
    }
};