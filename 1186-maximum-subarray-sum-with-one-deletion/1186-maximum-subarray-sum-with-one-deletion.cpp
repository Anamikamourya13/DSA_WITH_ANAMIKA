class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        int noDel =  a[0];
        int oneDel = INT_MIN;
        int res = a[0];

        for(int i= 1; i<n; i++){
            int prevNoDel = noDel;
            noDel = max(a[i], noDel + a[i]);
            if (oneDel == INT_MIN)
                oneDel = prevNoDel;
            else
            oneDel = max(prevNoDel, oneDel + a[i]);
            res= max(res, max(noDel, oneDel));
        }
        return res;
    }
};