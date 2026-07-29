// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1);

//         dp[0] = dp[1] = 1;

//         for(int i = 2; i <= n; i++)
//             dp[i] = dp[i-1] + dp[i-2];

//         return dp[n];
//     }
// };
class Solution {
public:
    int dfs(int n, vector<int>& dp){
        if(n <= 3) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = (dfs(n-1, dp) + dfs(n-2, dp));
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return dfs(n, dp);
    }
};