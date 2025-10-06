class Solution {
public:
    int maxDifference(string s) {
        // Maximum odd Frequency
        // Minum even Frequency to maximise the difference

        int hash[26] = {0} ;
        int n = s.size();

        int oddMax = INT_MIN;
        int evenMin = INT_MAX;

        for(int i = 0; i < n; i++){
            hash[s[i] - 'a']++ ;
        }

        for(int i = 0; i < 26; i++){
            if(hash[i] % 2 == 0 && hash[i] != 0){
                evenMin = min(evenMin, hash[i] );
            }

            if(hash[i]% 2 == 1){
                oddMax = max(oddMax, hash[i]);
            }
        }

        return oddMax - evenMin;
    }
};