class Solution {
public:
    int reverse(int x) {
        
        if (x == INT_MIN) return 0;

        int temp = abs(x);

        long long rev = 0;

        while(temp > 0){

            int ans = temp % 10;

            rev = rev * 10 + ans ;

            temp = temp/10 ;
        }


        if(rev < INT_MIN || rev > INT_MAX){
            return 0;
        }

         if(x < 0){
            return  (int) (-1)*rev ;
         }

         return (int)rev;

    }
};