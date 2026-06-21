class Solution {
   public:
    int getSum(int a, int b) {
        // 0001 0001
        // 0010

        // 0010 0010
        // 0100

        // 0010 0001
        // 0011

        while (b != 0) {
            int carry = (unsigned int)(a & b) << 1;

            a = a ^ b;

            b = carry;
        }

        return a;
    }
};
