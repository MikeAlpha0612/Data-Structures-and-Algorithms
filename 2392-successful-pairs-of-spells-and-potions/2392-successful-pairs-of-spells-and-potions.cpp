class Solution {
public:

    int binarySearch(long long num, vector<int>& potions, long long success){
      
        int n2 = potions.size();

        int left = 0;
        int right = n2 -1 ;
        int ans = n2;

        while(left <= right){

             int mid = (left + right)/2 ;

            if(num * potions[mid] >= success){
                right = mid -1 ;
                ans = mid;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n1 = spells.size();
        int n2 = potions.size();
        vector<int>answer;

        sort(potions.begin(), potions.end());

        for(int i = 0; i < n1; i++){

           

            long long num = spells[i];

            int ans = binarySearch(num,potions, success);

          
                answer.push_back(n2-ans);
            



        }

        return answer;
    }
};