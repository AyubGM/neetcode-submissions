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
        if (intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end(),
                  [](const Interval& a, const Interval& b) { return a.start < b.start; });

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int rooms = 1;
        minHeap.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            // If the earliest ending room is free before the current meeting starts
            if (intervals[i].start >= minHeap.top()) {
                minHeap.pop(); // Reuse this room (remove its old end time)
            }
            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    }
};
