class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> nums;

        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }

        int fact=1;
        for(int i=1;i<=n-1;i++){
            fact*=i;
        }
        k--;

        while(n>0){
            int idx=k/fact;
            
            ans+=to_string(nums[idx]);
            nums.erase(nums.begin()+idx);

            k%=fact;
            n--;

            if(n>0){
                fact/=n;
            }
        }
        return ans;
    }
};