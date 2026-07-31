class Solution {
public:
    int largestInteger(int n, int s) {
        for(int i = pow(10, n) - 1; i >= 0; i--){
            int temp = i, sum = 0;
            while(temp != 0){
                int dig = temp%10;
                sum += dig;
                temp /= 10;
            }

            if(sum == s) return i;
        }

        return -1;
    }
};