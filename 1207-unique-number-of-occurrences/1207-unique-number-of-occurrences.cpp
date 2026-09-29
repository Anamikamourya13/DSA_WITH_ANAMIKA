class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    map<int,int> frequency;   //hashmap ,frequency

      for(int x:arr){
        frequency[x]++;
      }  
      set<int>occurrences;   //occurences 

      for(auto it : frequency){
        int count = it.second;

        if(occurrences.find(count) != occurrences.end()){  //not unique occrrences
            return false;
        }
        occurrences.insert(count); // add
      }  
      return true; // return ans
    }
};