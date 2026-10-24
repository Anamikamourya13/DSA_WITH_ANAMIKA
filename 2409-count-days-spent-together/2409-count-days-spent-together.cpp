
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        // Days in each month (non-leap year)
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        // Convert MM-DD into day number of the year
        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }
            return day;
        };

        int aStart = convert(arriveAlice);
        int aEnd = convert(leaveAlice);
        int bStart = convert(arriveBob);
        int bEnd = convert(leaveBob);

        // Find common date range
        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);

        // +1 because both start and end days are included
        return max(0, end - start + 1);
    }
};
