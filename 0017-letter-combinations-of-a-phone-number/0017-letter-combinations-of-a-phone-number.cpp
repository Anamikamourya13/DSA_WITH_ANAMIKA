class Solution {
public:
    unordered_map<char,string>mp={
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void solve(int index, string &digits, string &temp, vector<string> &ans){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[index]];
        for(int j=0; j<letters.size(); j++){
            temp.push_back(letters[j]);
            solve(index +1, digits, temp, ans);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        string temp;

        solve(0, digits, temp, ans);

        return ans;
        
    }
};