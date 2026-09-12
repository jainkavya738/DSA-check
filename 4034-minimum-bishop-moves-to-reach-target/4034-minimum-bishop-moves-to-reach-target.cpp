class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int srcA = source[0], srcB = source[1];
        int destA = target[0], destB = target[1];

        for(int i = srcA + 1, j = srcB + 1; i <= 8, j <= 8; i++, j++){
            if(i == destA && j == destB) return 1;
        }

        for(int i = srcA - 1, j = srcB + 1; i >= 1, j <= 8; i--, j++){
            if(i == destA && j == destB) return 1;
        }

        for(int i = srcA + 1, j = srcB - 1; i <= 8, j >= 1; i++, j--){
            if(i == destA && j == destB) return 1;
        }

        for(int i = srcA - 1, j = srcB - 1; i >= 1, j >= 1; i--, j--){
            if(i == destA && j == destB) return 1;
        }

        if((srcA%2 == 0 && srcB%2 == 0) || (srcA%2 != 0 && srcB%2 != 0)){
            if((destA%2 == 0 && destB%2 == 0) || (destA%2 != 0 && destB%2 != 0)) return 2;
            else return -1;
        } else{
            if((destA%2 != 0 && destB%2 == 0) || (destA%2 == 0 && destB%2 != 0)) return 2;
            else return -1;
        }
    }
};