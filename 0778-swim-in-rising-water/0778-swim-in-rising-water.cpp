class Solution {
public:
    int swimInWater(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

    
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;


        vector<vector<int>> dist(n, vector<int>(m, 1e9));

         
         int dr[] = {-1, 1, 0, 0};
         int dc[] = {0, 0, -1, 1};
        
        
        pq.push({a[0][0], {0, 0}});
        dist[0][0] = a[0][0];



        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return time;

            if (time > dist[row][col])
                continue;

            for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newTime = max(time, a[nr][nc]);

                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1;
    }
};

