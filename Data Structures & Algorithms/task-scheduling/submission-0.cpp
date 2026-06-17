class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> count;
        std::priority_queue<std::pair<int, char>> pq;
        int time = 0;
        for (char c : tasks) {
            count[c]++;
        }

        for (const auto& [task, frq] : count) {
            pq.push({frq, task});
        }

        std::queue<std::pair<int, int>> q;
        while (!pq.empty() || !q.empty()) {
            time++;

            if (!pq.empty()) {
                auto [frq, task] = pq.top();
                pq.pop();
                frq--;

                int idel = n;

                if (frq > 0) {
                    q.push({frq, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                auto [frq, ready_time] = q.front();
                q.pop();
                pq.push({frq, ' '}); 
            }
        }

        return time;
    }
};
