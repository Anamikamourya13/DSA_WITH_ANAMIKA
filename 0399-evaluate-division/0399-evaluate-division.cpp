
class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;

    double dfs(string src, string dest,
               unordered_set<string>& visited) {

        if (adj.find(src) == adj.end() ||
            adj.find(dest) == adj.end()) {
            return -1.0;
        }

        if (src == dest) {
            return 1.0;
        }

        visited.insert(src);

        for (auto &edge : adj[src]) {
            string neighbor = edge.first;
            double weight = edge.second;

            if (visited.count(neighbor))
                continue;

            double result = dfs(neighbor, dest, visited);

            if (result != -1.0) {
                return weight * result;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        adj.clear();

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        // Answer each query
        for (auto &q : queries) {
            unordered_set<string> visited;

            ans.push_back(dfs(q[0], q[1], visited));
        }

        return ans;
    }
};
