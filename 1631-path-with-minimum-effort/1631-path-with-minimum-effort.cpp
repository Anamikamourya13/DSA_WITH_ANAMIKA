class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // minimum effort for each cell
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // {effort, {row, col}}
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        // start from (0,0)
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        // 4 directions
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int currEffort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // check 4 neighbours
            for(int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                // check valid cell
                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols) {

                    // height difference
                    int diff = abs(
                        heights[row][col] - heights[nr][nc]
                    );

                    // maximum difference in path
                    int newEffort = max(currEffort, diff);

                    // update if better
                    if(newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

        // answer
        return dist[rows-1][cols-1];
    }
};