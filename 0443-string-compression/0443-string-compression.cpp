class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();    
        int write = 0;           
        int i = 0;                

        while(i < n) {

            char current = chars[i];  // Current character store karo
            int count = 0;             // Current character ka count

            // Same character ko count karo
            while(i < n && chars[i] == current) {
                count++;
                i++;
            }

            // Character ko compressed array mein write karo
            chars[write] = current;
            write++;

            // Agar character ek se zyada baar aaya hai
            if(count > 1) {

            string s = to_string(count);

                for(char c : s) {
                    chars[write] = c;
                    write++;
                }
            }
        }

        // Compressed array ki length return karo
        return write;
    }
};