class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int n = candies.size();


// Find the maximum number of candies any kid currently has
    int maxCandies = *max_element(candies.begin(),candies.end());

    for(int i = 0; i<n; i++)
    {
        // Give all extra candies to the current kid
        int current = candies[i] + extraCandies; 
        
        // Check if current kid can have the greatest number of candies

        if(current >= maxCandies)
         ans.push_back(true);
        else
         ans.push_back(false);
    }

      return ans;

    }
};