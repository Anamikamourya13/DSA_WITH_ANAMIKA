class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int l = 0;              // left pointer
        int maxFreq = 0;       // max frequency in window
        int result = 0;        // answer

        for (int r = 0; r < s.size(); r++) {

            // step 1: add current character
            freq[s[r] - 'A']++;

            // step 2: update max frequency
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // step 3: check if window is valid
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            // step 4: update answer
            result = max(result, r - l + 1);
        }

        return result;
    }
};
       