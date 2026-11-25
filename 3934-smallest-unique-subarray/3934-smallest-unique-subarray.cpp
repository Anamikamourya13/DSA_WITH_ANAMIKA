

class Solution {
public:
    using ll = long long;

    const ll mod1 = 1000000007;
    const ll mod2 = 1000000009;
    const ll base = 100001;

    vector<ll> h1, h2, p1, p2;

    struct PairHash {
        size_t operator()(const pair<ll,ll>& p) const {
            return hash<ll>()(p.first) ^
                   (hash<ll>()(p.second) << 1);
        }
    };

    pair<ll,ll> getHash(int l, int r) {
        int len = r - l + 1;

        ll x = (h1[r+1] - h1[l] * p1[len] % mod1 + mod1) % mod1;
        ll y = (h2[r+1] - h2[l] * p2[len] % mod2 + mod2) % mod2;

        return {x, y};
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.assign(n+1, 0);
        h2.assign(n+1, 0);
        p1.assign(n+1, 1);
        p2.assign(n+1, 1);

        // Build prefix hashes
        for(int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * base + nums[i]) % mod1;
            h2[i+1] = (h2[i] * base + nums[i]) % mod2;

            p1[i+1] = p1[i] * base % mod1;
            p2[i+1] = p2[i] * base % mod2;
        }

        // Check if unique subarray exists
        auto check = [&](int len) {
            unordered_map<pair<ll,ll>, int, PairHash> freq;

            for(int i = 0; i + len <= n; i++) {
                auto hashValue = getHash(i, i+len-1);
                freq[hashValue]++;
            }

            for(auto &it : freq) {
                if(it.second == 1)
                    return true;
            }

            return false;
        };

        // Binary Search
        int low = 1, high = n;

        while(low < high) {
            int mid = low + (high-low)/2;

            if(check(mid))
                high = mid;
            else
                low = mid+1;
        }

        return low;
    }
};
