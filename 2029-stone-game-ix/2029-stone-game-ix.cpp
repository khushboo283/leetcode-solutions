class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]={0,0,0};

        for(int x:stones){
            cnt[x%3]++;
        }

        if(cnt[1]==0 || cnt[2]==0){ //if one remainder is absent
            return max(cnt[1],cnt[2])>2 && (cnt[0]%2==1);
        }

        return abs(cnt[1]-cnt[2])>2 || (cnt[0]%2==0); //both are present
    }
};