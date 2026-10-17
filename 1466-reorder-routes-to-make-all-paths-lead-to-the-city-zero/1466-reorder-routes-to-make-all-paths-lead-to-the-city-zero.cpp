
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &c : connections) {
            int a = c[0];
            int b = c[1];

            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }

        return dfs(0, -1, adj);
    }

    int dfs(int node, int parent,
            vector<vector<pair<int, int>>>& adj) {

        int count = 0;

        for (auto [neighbor, cost] : adj[node]) {
            if (neighbor == parent)
                continue;

            count += cost;
            count += dfs(neighbor, node, adj);
        }

        return count;
    }
};
