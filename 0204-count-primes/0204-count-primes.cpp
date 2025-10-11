class Solution {
public:
    int countPrimes(int n) {
        
        vector<int>sieve(n+1, 1);

           if(n == 0 || n == 1){
            return 0;
        }

        sieve[0] = 0;
        sieve[1] = 0;

      
     

        for(int i = 2 ; i*i < n; i++){

            if(sieve[i] == 1){
                for(int j = i*2; j < n; j += i){
                    sieve[j] = 0;
                }
            }

            
        }

        int cnt = 0;

        for(int i = 0; i < n ; i++){
            if(sieve[i] == 1){
                cnt++ ;
            }
        }

        return cnt;

        
    }
};