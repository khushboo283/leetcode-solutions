class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rows;

        for(auto &seat : reservedSeats){
            int row=seat[0];
            int col=seat[1];
            rows[row]|=(1<<col);
        }

        long long ans=2LL*(n-rows.size());

        for(auto &[row,mask] : rows){
            bool left=!(mask & ((1<<2)|(1<<3)|(1<<4)|(1<<5)));
            bool middle=!(mask & ((1<<4)|(1<<5)|(1<<6)|(1<<7)));
            bool right=!(mask & ((1<<6)|(1<<7)|(1<<8)|(1<<9)));

            if(left && right){
                ans+=2;
            }
            else if(left || middle || right){
                ans+=1;
            }
        }
        return ans;
    }
};