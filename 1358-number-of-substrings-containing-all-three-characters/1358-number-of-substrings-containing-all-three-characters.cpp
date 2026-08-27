class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int iA = -1, iB = -1, iC = -1, ans = 0;
        for(int r = 0; r < n; r++){
            if(s[r] == 'a') iA = r;
            else if(s[r] == 'b') iB = r;
            else iC = r;

            if(iA != -1 && iB != -1 && iC != -1) ans += (min({iA, iB, iC}) + 1);
        }

        return ans;
    }
};