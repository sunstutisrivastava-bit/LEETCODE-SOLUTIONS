class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // (weight, index)
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> freeServers;

        // (freeTime, index)
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for (int j = 0; j < m; j++) {

            // Task j arrives at time j.
            time = max(time, (long long)j);

            // Release all servers that are free by current time.
            while (!busyServers.empty() &&
                   busyServers.top().first <= time) {

                int idx = busyServers.top().second;

                busyServers.pop();

                freeServers.push({servers[idx], idx});
            }

            // If no server is free, jump to the earliest
            // time when a server becomes free.
            if (freeServers.empty()) {

                time = busyServers.top().first;

                // Multiple servers may become free at this same time.
                while (!busyServers.empty() &&
                       busyServers.top().first <= time) {

                    int idx = busyServers.top().second;

                    busyServers.pop();

                    freeServers.push({servers[idx], idx});
                }
            }

            // Choose the free server with minimum
            // (weight, index).
            auto [weight, idx] = freeServers.top();

            freeServers.pop();

            ans[j] = idx;

            // This server becomes free after processing the task.
            busyServers.push({
                time + tasks[j],
                idx
            });
        }

        return ans;
    }
};