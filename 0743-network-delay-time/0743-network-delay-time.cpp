class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);

        for(int i=0;i<times.size();i++){
            int u= times[i][0];
            int v=  times[i][1];
            int w=  times[i][2];

            graph[u].push_back({v,w});

        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        priority_queue<
           pair<int,int>,
           vector<pair<int,int>>,
           greater<pair<int,int>>>pq;

        pq.push({0,k});

       while(!pq.empty()){
        auto[distance,node]=pq.top();
        pq.pop();

       for(auto it : graph[node]) {
        int nextNode = it.first;
        int weight = it.second;

        if(distance + weight <dist[nextNode]){
          dist[nextNode]= distance + weight;
          pq.push({dist[nextNode],nextNode});

         }
       }
     }

   int ans = 0;

   for(int i = 1; i <= n; i++) {
    if(dist[i] == INT_MAX)
        return -1;

    ans = max(ans, dist[i]);
  }

   return ans;

       }
};