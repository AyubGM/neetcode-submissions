class Solution {
public:
    int maxArea(vector<int>& heights) {
      int maxArea = 0;

      int left = 0;
      int right = heights.size() - 1;
      
      while (left < right)
      {
        int hight = std::min(heights[left], heights[right]);
        int width = right - left;

        int currArea = hight * width;

        maxArea = std::max(maxArea, currArea);

        if(heights[left] < heights[right])
        {
          left++;
        }
        else
        {
          right--;
        }
      }


      return maxArea;
    }
};
