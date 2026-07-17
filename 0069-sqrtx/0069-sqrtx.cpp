class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;

        long long p=1;
        long long q=x;
        long long ans=0;

        while(p<=q){
            long long mid=p+(q-p)/2;

            if(mid*mid<=x){
                ans=mid;
                p=mid+1;
            }
            else{
                q=mid-1;
            }
        }
        return ans;
    }
};