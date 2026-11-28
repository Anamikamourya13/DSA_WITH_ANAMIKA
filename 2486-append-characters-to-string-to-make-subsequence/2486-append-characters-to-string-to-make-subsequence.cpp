class Solution {
public:
    int appendCharacters(string s, string t) {
      int i  =0 ;
      int j=0;

      while(i<s.length() & j<t.length()){
        if(s[i] == t[j]){
            i=i+1;
            j=j+1; //character matchhed move it
        }
        else{
            i=i+1; //no match search next character in S 
        }
      } 
      return (t.length() - j); 
    }
};