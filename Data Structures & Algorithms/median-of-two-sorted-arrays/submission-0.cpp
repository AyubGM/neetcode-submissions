class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        int halfTotal = total /2;

        if (n1 > n2) {
            std::swap(nums1, nums2);
            std::swap(n1, n2);
        }

        int l = 0;
        int r = n1 - 1;
        while (true) {
            int i = (l <= r) ? (l + (r - l) / 2) : -1;  // mid for nums1
            int j = halfTotal - i - 2;    // "mid" for nums2

            int leftN1 = (i >= 0) ? nums1[i] : INT_MIN;
            int rightN1 = (i + 1 < n1) ? nums1[i + 1] : INT_MAX;

            int leftN2 = (j >= 0) ? nums2[j] : INT_MIN;
            int rightN2 = (j + 1 < n2) ? nums2[j + 1] : INT_MAX;

            if (leftN1 <= rightN2 && leftN2 <= rightN1) {
                if (total % 2)  // for odd total
                {
                    return std::min(rightN1, rightN2);
                }

                // for even total

                return (std::max(leftN1, leftN2) + std::min(rightN1, rightN2)) / 2.0;

            } else if (leftN1 > rightN2) {
                r = i -1;
            } else
            {
                l = i + 1;
            }
        }
    }
};
