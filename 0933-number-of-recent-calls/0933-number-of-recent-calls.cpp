class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {

    }
    
    //new call add 
    int ping(int t) {
        q.push(t);
        
        //3000ms se purani calls remove kro
        while(q.front() < t-3000){
            q.pop();
        }
       return q.size(); //recent calls ki count
    }
};

