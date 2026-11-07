
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> freeServers;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        long long currTime = 0;

        for (int j = 0; j < m; j++) {

            currTime = max(currTime, (long long)j);

            // Release completed servers
            while (!busyServers.empty() &&
                   get<0>(busyServers.top()) <= currTime) {

                auto [t, w, idx] = busyServers.top();
                busyServers.pop();

                freeServers.push({w, idx});
            }

            // Wait if all servers are busy
            if (freeServers.empty()) {
                currTime = get<0>(busyServers.top());

                while (!busyServers.empty() &&
                       get<0>(busyServers.top()) <= currTime) {

                    auto [t, w, idx] = busyServers.top();
                    busyServers.pop();

                    freeServers.push({w, idx});
                }
            }

            // Assign the task
            auto [weight, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;

            busyServers.push({
                currTime + tasks[j], weight, idx
            });
        }

        return ans;
    }
};
