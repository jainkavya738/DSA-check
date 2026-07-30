class Solution {
public:
    map<pair<int, int>, bool> dp;
    bool helper(int n, map<int, int>& m, vector<int>& stones, int currPos, int prevJump){
        if(currPos >= n || prevJump <= 0) return false;

        if(currPos == (n-1)) return true;

        currPos = stones[currPos];
        
        if(dp.count({currPos, prevJump})) return dp[{currPos, prevJump}];

        if(m.find(currPos + prevJump + 1) != m.end() && helper(n, m, stones, m[currPos + prevJump + 1], prevJump + 1)) return dp[{currPos, prevJump}] = true;
        if(m.find(currPos + prevJump) != m.end() && helper(n, m, stones, m[currPos + prevJump], prevJump)) return dp[{currPos, prevJump}] = true;
        if(m.find(currPos + prevJump - 1) != m.end() && helper(n, m, stones, m[currPos + prevJump - 1], prevJump - 1)) return dp[{currPos, prevJump}] = true;

        return dp[{currPos, prevJump}] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(stones[1] != 1) return false;

        map<int, int> m;
        for(int i = 0; i < n; i++) m[stones[i]] = i;

        return helper(n, m, stones, 1, 1);
    }
};