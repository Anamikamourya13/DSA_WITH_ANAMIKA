
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available: {weight, index}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        // Busy: {freeTime, weight, index}
        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        // Initially all servers are available
        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;

        for(int i = 0; i < m; i++) {

            // Release servers whose work is completed
            while(!busy.empty() && get<0>(busy.top()) <= i) {

                auto [time, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if(available.empty()) {

                auto [time, weight, index] = busy.top();
                busy.pop();

                ans.push_back(index);

                busy.push({time + tasks[i], weight, index});
            }

            else {

                auto [weight, index] = available.top();
                available.pop();

                ans.push_back(index);

                busy.push({i + tasks[i], weight, index});
            }
        }

        return ans;
    }
};
