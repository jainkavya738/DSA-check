class Solution {
public:
    //GOOODDDDD QUES...... IMPLEMENTATION SOCHNA MUSHKIL HAI
    string minWindow(string s, string t) {
        int l = 0; unordered_map<char, int> need, have;
        for(char c : t) need[c]++;
        
        int start = 0, formed = 0, minLen = INT_MAX;
        for(int r = 0; r < s.size(); r++){
            have[s[r]]++;
            
            if(need.count(s[r]) && have[s[r]] == need[s[r]]) formed++;

            while(formed == need.size()){
                if((r - l + 1) < minLen){
                    minLen = (r - l + 1);
                    start = l;
                }

                if(need.count(s[l])){ 
                    if(have[s[l]] == need[s[l]]) formed--;

                    have[s[l]]--;
                }

                l++;
            }
        }

        if(minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};