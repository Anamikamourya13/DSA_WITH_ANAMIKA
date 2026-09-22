class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        stack<string> st;
        string word;

        while(ss >> word)
        {
            st.push(word);
        }

        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();

            if(!st.empty())
                ans += " ";
        }

        return ans;
    }
};
    