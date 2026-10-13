
class Solution {
public:
    vector<vector<string>> suggestedProducts(
        vector<string>& products, string searchWord) {

        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for (char ch : searchWord) {
            prefix += ch;
            vector<string> suggestions;

            for (string& product : products) {
                // Sorted products: only matching prefixes qualify
                if (product.find(prefix) == 0) {
                    suggestions.push_back(product);
                }

                // We need at most 3 suggestions
                if (suggestions.size() == 3) {
                    break;
                }
            }

            ans.push_back(suggestions);
        }

        return ans;
    }
};
