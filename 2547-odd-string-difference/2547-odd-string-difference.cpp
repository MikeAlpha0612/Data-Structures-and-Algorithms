class Solution {
public:
    string oddString(vector<string>& words) {

        int n = words.size();
        vector<vector<int>>count(n);
        
      for(int i = 0; i < n; i++){

        for(int j = 0; j < words[i].size()-1; j++){

            count[i]. push_back(words[i][j+1] - words[i][j]);
        }
      }

      map<vector<int>,int>mpp;
      vector<int>bluff;

      for(auto it : count){
        mpp[it]++ ;
      }

      for(auto it : mpp){
        if(it.second == 1){
          bluff = it.first;
          break;
        }
      }

      for(int i = 0; i < n; i++){

        if(count[i] == bluff){
            return words[i];
        }
      }

      return "" ;
       

    }
};