class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
      std::priority_queue<int> pq(stones.begin(), stones.end());

      while (pq.size() > 1)
      {
        int x = pq.top();
        pq.pop();

        int y = pq.top();
        pq.pop();

        int val = x - y;
        
        if (val != 0)
        {
            pq.push(val);
        }
      }

      return pq.empty()? 0 : pq.top();

    }
};
