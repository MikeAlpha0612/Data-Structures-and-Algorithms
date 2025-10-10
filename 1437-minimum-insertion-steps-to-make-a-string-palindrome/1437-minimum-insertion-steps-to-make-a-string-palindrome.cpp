#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int result(std::string& s, std::string& str, int n1, int n2, std::vector<std::vector<int>>& dp) {
        // Base case: if one string is empty, we must insert/delete all
        // characters of the other string.
        if (n1 < 0) return n2 + 1;
        if (n2 < 0) return n1 + 1;

        if (dp[n1][n2] != -1) {
            return dp[n1][n2];
        }

        // If characters match, no operation is needed for them.
        if (s[n1] == str[n2]) {
            return dp[n1][n2] = result(s, str, n1 - 1, n2 - 1, dp);
        }

        // If they don't match, we pay a cost of 1 and take the minimum of
        // deleting from s (n1-1) or inserting into s (n2-1).
        return dp[n1][n2] = 1 + std::min(result(s, str, n1 - 1, n2, dp), 
                                         result(s, str, n1, n2 - 1, dp));
    }

    int minInsertions(std::string s) {
        int n = s.size();
        
        // FIX: Declare str as a string and reverse efficiently
        std::string str = s;
        std::reverse(str.begin(), str.end());

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));

        int edit_distance = result(s, str, n - 1, n - 1, dp);

        // FIX: The answer is the calculated edit distance divided by 2
        return edit_distance / 2;
    }
};