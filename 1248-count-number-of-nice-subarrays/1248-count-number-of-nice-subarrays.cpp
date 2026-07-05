class Solution {
public:
    int atMost(vector<int>& nums,int goal){
        if(goal<0) return 0;

        int l=0;
        int sum=0;
        int count=0;

        for(int r=0;r<nums.size();r++){
            sum+=nums[r]%2;

            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            count+=(r-l+1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};