class Solution {
public:
    int minimumFlips(int n) {
        int temp = n; string s;
        while(temp){
            int dig = temp%2;
            s.push_back('0' + dig);
            temp /= 2;
        }

        string temp1 = s;
        reverse(temp1.begin(), temp1.end());
        
        int count = 0;
        for(int i = 0; i < temp1.size(); i++){
            if(temp1[i] != s[i]) count++;
        }

        return count;
    }
};