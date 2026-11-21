
class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj;

    void dfs(int node, vector<vector<int>>& tree,
             vector<int>& newParent, vector<int>& last) {

        int c = s[node] - 'a';
        int old = last[c];

        if (node != 0 && old != -1)
            newParent[node] = old;

        last[c] = node;

        for (int child : tree[node])
            dfs(child, tree, newParent, last);

        last[c] = old;
    }

    string s;

    int calc(int node) {
        int size = 1;

        for (int child : adj[node])
            size += calc(child);

        answer[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;

        vector<vector<int>> tree(n);
        vector<int> newParent = parent;

        for (int i = 1; i < n; i++)
            tree[parent[i]].push_back(i);

        vector<int> last(26, -1);

        dfs(0, tree, newParent, last);

        adj.assign(n, {});

        for (int i = 1; i < n; i++)
            adj[newParent[i]].push_back(i);

        answer.assign(n, 0);
        calc(0);

        return answer;
    }
};
