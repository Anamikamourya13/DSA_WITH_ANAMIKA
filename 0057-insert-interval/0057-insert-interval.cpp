class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
     vector<vector<int>> temp;
     bool inserted = false;

     for(int i=0; i<interval.size();i++){
        if(!inserted && interval[i][0] >= newInterval[0]){
        temp.push_back(newInterval);
        inserted =  true;
        }
      
      temp.push_back(interval[i]);
     }
      if (!inserted) {
       temp.push_back(newInterval);
    }
       //merge intervals
    sort(interval.begin(),interval.end());
    vector<vector<int>> res;
    int start1 = temp[0][0];
    int end1 = temp[0][1];
    int n = temp.size();
    for(int i=1; i<n;i++)
    {
        int start2=temp[i][0];
        int end2=temp[i][1];
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