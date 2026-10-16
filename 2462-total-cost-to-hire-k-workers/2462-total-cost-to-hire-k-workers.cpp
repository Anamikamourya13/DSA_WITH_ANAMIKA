
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Min-heaps: always give the cheapest available worker
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;

        int i = 0;
        int j = costs.size() - 1;

        // Add candidates from the left side
        while (i <= j && left.size() < candidates) {
            left.push(costs[i]);
            i++;
        }

        // Add candidates from the right side without overlap
        while (i <= j && right.size() < candidates) {
            right.push(costs[j]);
            j--;
        }

        long long total = 0;

        // Hire exactly k workers
        for (int hire = 0; hire < k; hire++) {
            // Choose left if costs are equal (smaller original index)
            if (right.empty() ||
                (!left.empty() && left.top() <= right.top())) {

                total += left.top();
                left.pop();

                // Refill from the remaining left side
                if (i <= j) {
                    left.push(costs[i]);
                    i++;
                }
            } else {
                total += right.top();
                right.pop();

                // Refill from the remaining right side
                if (i <= j) {
                    right.push(costs[j]);
                    j--;
                }
            }
        }

        return total;
    }
};
