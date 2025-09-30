class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;

        int n = s.size();
        string temp ="";

        for(int i = 0; i < n; i++){
            if(s[i] != ' '){
                temp += s[i];
            }else{
                if(!temp.empty()){
                    st.push(temp);
                    temp ="" ;
                }
            }
        }

        if(!temp.empty()){
            st.push(temp);
        }

        string res ="" ;

        while(!st.empty()){
            
            res += st.top();
            res = res + " " ;
            st.pop();
        }

        res.pop_back();

        return res;

    }
};