class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int x = 0, y = 0;
        while(x < g.size() && y < s.size()){
            if(s[y] >= g[x]) x++;

            y++;
        }

        return x;
    }
};