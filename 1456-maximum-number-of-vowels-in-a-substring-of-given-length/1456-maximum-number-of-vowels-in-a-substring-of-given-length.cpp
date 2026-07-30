class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' ||
                ch == 'i' || ch == 'o' ||
                ch == 'u');
    }

    int maxVowels(string s, int k) {
        int current = 0;
        int maximum = 0;

        // Count vowels in first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                current++;
        }

        maximum = current;

        // Slide the window
        for (int i = k; i < s.length(); i++) {

            // Remove left character
            if (isVowel(s[i - k]))
                current--;

            // Add right character
            if (isVowel(s[i]))
                current++;

            maximum = max(maximum, current);
        }

        return maximum;
    }
};