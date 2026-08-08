class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        
        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Step 2: Count last word
        int count = 0;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        
        return count;
    }
};