class Solution {
public:
    int appendCharacters(string s, string t) {
      int i  =0 ;
      int j=0;

      while(i<s.length() & j<t.length()){
        if(s[i] == t[j]){
            i=i+1;
            j=j+1;
        }
        else{
            i=i+1;
        }
      } 
      return (t.length() - j); 
    }
};