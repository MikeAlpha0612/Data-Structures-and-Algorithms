class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();

        vector<char>vowels = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_set<char>st;

        for(int i = 0; i < vowels.size() ; i++){
            st.insert(vowels[i]);
        }

        vector<char>resVowels;

        for(int i = 0; i < n ; i++){
           
           if(st.find(s[i]) != st.end()){
            resVowels.push_back(s[i]);
           }
           
            
        }

        sort(resVowels.begin(), resVowels.end());
        string res;
        int j = 0;

        for(int i = 0; i < n; i++){
             
             if(st.find(s[i]) != st.end()){
                res.push_back(resVowels[j++]);
                
             }else{
                res.push_back(s[i]);
             }
        }
         
         return res;

    }
};