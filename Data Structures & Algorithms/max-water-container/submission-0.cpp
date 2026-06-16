class Solution {
public:
    int maxArea(vector<int>& heights) {
      int maxArea = 0;

      int left = 0;
      int right = heights.size() - 1;

      while (left < right)
      {
            int width = right - left;
            int height = std::min(heights[left], heights[right]);

            int currentArea = width * height;
            
            maxArea = std::max(maxArea, currentArea);

            if(heights[left] < heights[right])
            {
              left++;
            } else
            {
                right--;
            }
            
      } 
        return maxArea;
    }
};
