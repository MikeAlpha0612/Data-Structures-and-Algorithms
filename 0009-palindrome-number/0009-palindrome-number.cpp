class Solution {
public:
    bool isPalindrome(int x) {
        
        string str = to_string(x);
        string str1 = str;
         reverse(str.begin(), str.end());

        if(str == str1){
            return true;
        }

        return false;
    }
};