class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        //1st window
        for(int i=0;i<k;i++){
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k;i<nums.size();i++){
            result.push_back(nums[dq.front()]);

            //remove el not part of curr window
            while(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }

            //remove smaller vals from the end
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        return result;
    }
};