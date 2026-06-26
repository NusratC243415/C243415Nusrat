#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency List
        vector<pair<int, int>> adj[n + 1];

        // Build the graph
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min Heap -> {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if (d > dist[u])
                continue;

            // Traverse all neighbors
            for (auto &it : adj[u]) {

                int v = it.first;
                int w = it.second;

                if (dist[u] + w < dist[v]) {

                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Find the maximum shortest distance
        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};

