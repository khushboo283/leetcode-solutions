class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n=numWays.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(numWays[i]==1){
                int coin=i+1;
                ans.push_back(coin);
                for(int j=n-1;j>=i+1;j--){
                    numWays[j]-=numWays[j-coin];
                }
                numWays[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(numWays[i]!=0){
                return {}; 
            }
        }
        return ans;
    }
};