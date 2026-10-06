class StockSpanner {
public:
    stack<int>st;
    vector<int>prices;
    int i=0;

    StockSpanner(){   

    }
    int next(int price){
        prices.push_back(price);

 // Smaller/equal prices can't be the previous greater
        while(!st.empty() && prices[st.top()]<= price){

            st.pop();
        }

        int span;
        if(st.empty()){ // No previous greater → all previous days included

            span = i+1;
        }
        else{       //// Previous greater is at st.top()
            span =i-st.top();
        }

           // Store current index for future days
        st.push(i);
        i++;
        return span;
    }
};