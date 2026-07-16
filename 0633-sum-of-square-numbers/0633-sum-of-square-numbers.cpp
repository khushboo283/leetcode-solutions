class Solution {
public:
    bool judgeSquareSum(int c) {
        long long p=0;
        long long q=sqrt(c);

        while(p<=q){
            long long sum=p*p+q*q;

            if(sum==c){
                return true;
            }
            else if(sum<c){
                p++;
            }
            else{
                q--;
            }
        }
        return false;
    }
};