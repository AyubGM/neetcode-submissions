class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int gk;

public:
    KthLargest(int k, vector<int>& nums) {
       gk = k;
        for (int num : nums) {
            add(num); 
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > gk) {
            pq.pop();
        }

        return pq.top();
    }
};
