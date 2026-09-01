class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefSum(n), suffSum(n);

        prefSum[0] = cardPoints[0];
        for(int i = 1; i < n; i++) prefSum[i] = (prefSum[i-1] + cardPoints[i]);

        suffSum[n-1] = cardPoints[n-1];
        for(int i = n-2; i >= 0; i--) suffSum[i] = (suffSum[i+1] + cardPoints[i]);
        
        int ans = INT_MIN;
        for(int l = 0; l <= k; l++){
            int r = (k - l);

            int left = (l == 0)? 0 : prefSum[l-1];
            int right = (r == 0)? 0 : suffSum[n-r];

            ans = max(ans, left + right);
        }

        return ans;
    }
};