class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<minimum){
                minimum=nums[i];
            }
        }
        return minimum;
    }
};