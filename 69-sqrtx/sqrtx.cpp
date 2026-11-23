class Solution {
public:
using ll=long long;
    int mySqrt(int x2) {
        ll x=x2;
  ll ans=0;
  while(ans*ans<=x){
    ans++;
  }     
  return ans-1;
    }
};