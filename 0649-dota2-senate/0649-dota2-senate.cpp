class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> R, D;
        int n = senate.size();

        // R and D senators ki positions store karo
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R')
                R.push(i);
            else
                D.push(i);
        }

        // Jab tak dono parties ke senators bache hain
        while(!R.empty() && !D.empty()) {

            int r = R.front();
            int d = D.front();

            // Jo pehle aaya, woh opponent ko ban karega
            if(r < d) {

                R.pop();
                D.pop();

                // R next round mein wapas aayega
                R.push(r + n);
            }
            else {

                R.pop();
                D.pop();

                // D next round mein wapas aayega
                D.push(d + n);
            }
        }

        // Jiski queue empty ho gayi, woh haar gaya
        if(R.empty())
            return "Dire";

        return "Radiant";
    }
};