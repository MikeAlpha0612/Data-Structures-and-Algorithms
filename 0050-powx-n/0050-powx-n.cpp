class Solution {
public:
    double myPow(double x, int n) {

     double ans = 1;
     long long N = n;

     if( N < 0){
        x = 1/x;
        N = -1 * N ;
     }

     while(N > 0){

        if(N % 2 == 0){
          
          x = x * x;
          N = N/2 ;

        }else{
          
          ans = ans * x ;
          N = N-1 ;
        }
     }

     return ans;
     

        
    }
};