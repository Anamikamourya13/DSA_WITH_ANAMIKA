class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;

        for (char ch : text) {
            have[ch]++;
        }

       
        unordered_map<char, int> need;

        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        int res = INT_MAX;

        
        for (auto p : need) {

            char c = p.first;      // Character
            int fneed = p.second;  // Required frequency
            int fhave = have[c];   // Available frequency

            int times = fhave / fneed;

            res = min(res, times);
        }

        return res;
    }
};