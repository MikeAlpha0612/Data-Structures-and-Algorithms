class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int>result;

        string str;
        str += x;

        for(int i = 0; i < n; i++){
           string it = words[i];

             if(find(it.begin(), it.end(), str) != it.end()){
                result.push_back(i);
            }
          
        }

        return result;
    }
};