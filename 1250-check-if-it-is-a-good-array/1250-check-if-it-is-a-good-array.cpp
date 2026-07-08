class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g=nums[0];
        for(int val:nums)
            g=std::gcd(g,val);
        return g==1;
    }
};