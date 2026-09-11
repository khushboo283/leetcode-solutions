class Solution {
public:
    int totalNumbers(vector<int>& d) {
        int ans=0;
        for(int n=100;n<=998;n+=2){
            int f[10]={};
            for(int x:d){
                f[x]++;
            }

            int a=n/100,b=n/10%10,c=n%10;
            if(--f[a]>=0 && --f[b]>=0 && --f[c]>=0){
                ans++;
            }
        }
        return ans;
    }
};