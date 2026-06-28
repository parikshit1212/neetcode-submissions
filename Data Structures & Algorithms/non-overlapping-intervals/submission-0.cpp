class Solution {
public:
    bool static cmp(vector<int> interval1, vector<int> interval2) {
        return interval1[1] < interval2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int endTimeForLastPickedInterval = intervals[0][1];
        int pickedIntervalsCount = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= endTimeForLastPickedInterval) {
                endTimeForLastPickedInterval = intervals[i][1];
                pickedIntervalsCount++;
            }
        }
        return intervals.size()-pickedIntervalsCount;
    }
};