class Solution {
public:
    static const int MOD=1000000007;
    int numberOfSets(int m, int k) {
        int n=m+k-1;
        vector<vector<int>> c(n+1,vector<int>(2*k+1,0));
        c[0][0]=1;

        for(int i=1;i<=n;i++){
            c[i][0]=1;

            for(int j=1;j<=min(i,2*k);j++){
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
            }
        }
        return c[n][2*k];
    }
};