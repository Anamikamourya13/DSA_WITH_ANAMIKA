class Solution { 
public: 
    int fun(vector<int> &a, int i, int n, int prev, vector<vector<int>>& dp) 
    { 
        // Array ke end tak pahunch gaye
        if(i == n)
            return 0;

        // Agar ye state pehle calculate ho chuki hai,
        // toh dobara recursion nahi karenge
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

    
        int c1 = 0;
        int c2 = 0;

        // Current element tabhi le sakte hain
        // jab koi previous element nahi hai
        // OR current element previous se bada hai
        if(prev == -1 || a[i] > a[prev])
        {
            // Current element liya
            // length +1 hogi
            // prev ab current index i ban jayega
            c1 = 1 + fun(a, i + 1, n, i, dp);
        }

        // Current element ko skip kar diya
        // prev same rahega
        c2 = fun(a, i + 1, n, prev, dp);

        // TAKE aur SKIP mein jo maximum hai,
        // wahi LIS ka answer hoga
        return dp[i][prev + 1] = max(c1, c2);
    }

    int lengthOfLIS(vector<int>& a) 
    {
        int n = a.size();

        // dp[i][prev+1]
        // i = current index
        // prev = previous selected element ka index
        //
        // prev -1 bhi ho sakta hai,
        // isliye prev+1 use kiya hai
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Starting mein:
        // i = 0
        // prev = -1 (abhi koi element select nahi hua)
        return fun(a, 0, n, -1, dp);
    }
};