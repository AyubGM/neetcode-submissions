class Solution {
    int SumOfSquares(int n)
    {
        int res = 0;

        while (n > 0)
        {
            int digit = n % 10;
            digit = digit * digit;
            res += digit;
            n /= 10;
        }

        return res;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        

        while (!seen.contains(n))
        {
            seen.insert(n);
            n = SumOfSquares(n);

            if (n == 1) return true;
        }

        return false;

    }
};
