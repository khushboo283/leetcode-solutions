class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();

        if(k==0) return 1;

        vector<int> count(6,0);
        int currOR=0;
        int ans=INT_MAX;
        int left=0;

        for(int right=0;right<n;right++){
            for(int i=0;i<6;i++){
                if(nums[right] & (1<<i)){
                    count[i]++;
                    currOR |=(1<<i);
                }
            }
            while(left<=right && currOR>=k){
                ans=min(ans,right-left+1);

                for(int i=0;i<6;i++){
                    if(nums[left] & (1<<i)){
                        count[i]--;
                        if(count[i]==0){
                            currOR &= ~(1<<i);
                        }
                    }
                }
                left++;
            }
        }
        return (ans==INT_MAX)? -1 : ans;
    }
};