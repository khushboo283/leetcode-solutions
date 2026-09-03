class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;

        for(int x:nums1){
            mini=min(mini,x);
        }

        if(mini%2==1){
            return true;
        }

        for(int x:nums1){
            if(x%2==1){
                return false;
            }
        }
        return true;
    }
};