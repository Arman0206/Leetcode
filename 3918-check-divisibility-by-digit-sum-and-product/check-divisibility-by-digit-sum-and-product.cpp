class Solution {
public:
    bool checkDivisibility(int n) {
       int x=n;
       int s=0;
       int p=1;
       while(x){
        s+=(x%10);
        x/=10;
       }
       x=n;
        while(x){
        p*=(x%10);
        x/=10;
       }
       s+=p;
       if(n%s)
       return false;
       return true;



    }
};