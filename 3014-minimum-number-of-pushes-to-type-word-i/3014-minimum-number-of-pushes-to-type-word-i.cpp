class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;

        ans+=min(n,8);
        n-=min(n,8);

        ans+=2*min(n,8);
        n-=min(n,8);

        ans+=3*min(n,8);
        n-=min(n,8);

        ans+=4*min(n,8);

        return ans;
    }
};