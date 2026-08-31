class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int temp = n; map<int, int> m;
        while(temp){
            int dig = temp%10;
            m[dig]++;
            temp /= 10;
        }
        
        int mini = INT_MAX, ans = 0;
        for(auto& p: m){
            if(p.second < mini){
                mini = p.second;
                ans = p.first;
            } else if(p.second == mini) ans = min(ans, p.first);
        }

        return ans;
    }
};