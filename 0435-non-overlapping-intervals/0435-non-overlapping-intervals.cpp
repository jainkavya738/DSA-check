class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int count = 0, lastEnd = INT_MIN;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEnd){
                lastEnd = intervals[i][1];
                count++;
            }
        }

        return (intervals.size() - count);
    }
};