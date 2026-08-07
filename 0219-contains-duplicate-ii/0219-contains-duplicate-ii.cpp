class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> lastIdx;

        for(int i=0;i<n;i++){
            if(lastIdx.count(nums[i]) && i-lastIdx[nums[i]]<=k){
                return true;
            }
            lastIdx[nums[i]]=i;
        }
        return false;
    }
};