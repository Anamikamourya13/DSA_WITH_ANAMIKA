class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
    sort(a.begin(),a.end());
    vector<vector<int>> res;
    int start1 = a[0][0];
    int end1 = a[0][1];
    int n = a.size();
    for(int i=1; i<n;i++)
    {
        int start2=a[i][0];
        int end2=a[i][1];
        if(end1>=start2)
        {
            start1 = start1;
            end1 =max(end1,end2);
            continue;
        }
        res.push_back({start1,end1});
         start1= start2;
         end1=end2;
    }
        res.push_back({start1,end1});
        return res;
        
    }
};