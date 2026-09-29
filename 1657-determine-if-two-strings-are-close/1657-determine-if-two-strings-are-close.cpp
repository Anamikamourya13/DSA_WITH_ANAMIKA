class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // Length different hai to close nahi ho sakte
        if (word1.length() != word2.length()) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Frequency count
        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        // Check: dono me same characters present hone chahiye
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] > 0) != (freq2[i] > 0)) {
                return false;
            }
        }

        // Frequency pattern compare
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};