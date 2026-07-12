class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());

        map<int,int> m;
        int rank=1;

        for(int x:temp){
            if(m.find(x)==m.end()){
                m[x]=rank;
                rank++;
            }
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }

        return arr;
    }
};