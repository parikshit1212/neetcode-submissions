/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startTime;
        vector<int> endTime;
        for(int i = 0; i < intervals.size(); i++) {
            startTime.push_back(intervals[i].start);
            endTime.push_back(intervals[i].end);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        int startIdx = 0;
        int endIdx = 0;
        int n = startTime.size();
        int count = 0;
        int maxRooms = 0;
        while(startIdx < n && endIdx < n) {
            if (startTime[startIdx] == endTime[endIdx]) {
                // one room getting empty and one is being used so no room count change
                startIdx++;
                endIdx++;
            }
            else if (startTime[startIdx] < endTime[endIdx]) {
                startIdx++;
                count++;
            } else {
                endIdx++;
                count--;
            }

            maxRooms = max(maxRooms, count);
        }
        return maxRooms;
    }
};
