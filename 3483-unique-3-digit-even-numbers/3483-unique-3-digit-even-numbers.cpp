class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        unordered_set<int> s;

        int n = digits.size();

        for(int i = 0; i < n; i++)
        {
            // last digit even hona chahiye
            if(digits[i] % 2 == 1)
                continue;

            for(int j = 0; j < n; j++)
            {
                // same position dobara use nahi karna
                if(i == j)
                    continue;

                for(int k = 0; k < n; k++)
                {
                    // first digit 0 nahi ho sakta
                    // aur same position use nahi kar sakte
                    if(digits[k] == 0 || k == i || k == j)
                        continue;

                    int num = digits[k] * 100
                            + digits[j] * 10
                            + digits[i];

                    s.insert(num);
                }
            }
        }

        return s.size();
    }
};