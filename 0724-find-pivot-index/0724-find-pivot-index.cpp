class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int i =  0;
        int n=a.size();
        int sum=0;
        for(i=0;i<n; i++)
        sum+=a[i];
        int left=0;
        for(i=0; i<n; i++)
        {
            int right = sum - left -a[i];
            if (left==right)
            return i;

            left  = left+a[i];
        }
        return -1;
    }
};