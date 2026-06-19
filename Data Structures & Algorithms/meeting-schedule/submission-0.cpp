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
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        Interval current = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (current.end > intervals[i].start)
            {
                return false;
            }
            current = intervals[i];
        }

        return true;
    }
};
