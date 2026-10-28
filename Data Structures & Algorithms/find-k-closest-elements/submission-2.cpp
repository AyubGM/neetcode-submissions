class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int l = 0;
        int r = arr.size() - 1;
        
       
        while (r - l + 1 > k) {
            if (std::abs(arr[l] - x) > std::abs(arr[r] - x)) {
                l++; 
            } else {
                r--; 
            }
        }
        
        return std::vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};