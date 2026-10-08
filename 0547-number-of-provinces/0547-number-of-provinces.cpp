class Solution {
public:
    vector<bool> visited;

    void dfs(int city, vector<vector<int>>& isConnected) {
        visited[city] = true;

        for(int j = 0; j < isConnected.size(); j++) {

            if(isConnected[city][j] == 1 &&
               visited[j] == false) {

                dfs(j, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        visited = vector<bool>(n, false);

        int count = 0;

        for(int i = 0; i < n; i++) {

            if(visited[i] == false) {

                count++;
                dfs(i, isConnected);
            }
        }

        return count;
    }
};