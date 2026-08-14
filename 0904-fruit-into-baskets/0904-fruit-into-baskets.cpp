class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int i = 0, ans = 0;
        unordered_map<int, int> m;

        //ek time pe do hi types ko andar rehne do window ke.... agr ek bhi jyaaada aaye toh remove krdo pichli wali ko aur maximum ans ko save krlo
        
        for(int j = 0; j < n; j++){
            m[fruits[j]]++;

            while(m.size() > 2){
                m[fruits[i]]--;

                if(m[fruits[i]] == 0) m.erase(fruits[i]);

                i++;
            }   

            ans = max(ans, (j - i + 1));
        }

        return ans;
    }
};