class Solution {
public:
    int xorOperation(int n, int start) {
        
        int n0 = start + 2 * 0 ;

        for(int i = 1; i < n ; i++){
            n0 = n0 ^ (start + 2*i);
        }

        return n0;
    }
};