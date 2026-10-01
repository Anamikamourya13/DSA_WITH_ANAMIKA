class Solution {
public:
    string decodeString(string s) {
    stack<pair<int,string>> st;

    int num=0;
    string current ="";

    for(char ch : s){
        //number build

        if(isdigit(ch)){
            num = num*10 + (ch-'0');
        }
        //current state ko stack me save karo

        else if(ch == '['){
           st.push({num,current});

           num=0;
           current ="";

        }

        //string ko repeat kro
        else if(ch == ']'){
            int repeat = st.top().first;
            string previous = st.top().second;

            st.pop();


            string temp ="";
            for(int i=0; i<repeat; i++){

                temp+= current;
            }
            current = previous + temp;
        }

        else{
            current += ch;
        }
    }    
    return current;
    }
};