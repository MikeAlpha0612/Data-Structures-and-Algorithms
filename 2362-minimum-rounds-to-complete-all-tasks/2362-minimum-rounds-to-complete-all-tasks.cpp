class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int>mpp;

        for(int i = 0; i < tasks.size(); i++){
            mpp[tasks[i]]++ ;
        }

        int count = 0;

        for(auto it : mpp){

            if(it.second < 2){
                return -1;
            }
            
            count += it.second/3;
             
              if(it.second % 3 != 0){
                count +=1 ;
              }
            
        }

        return count;

        
    }
};