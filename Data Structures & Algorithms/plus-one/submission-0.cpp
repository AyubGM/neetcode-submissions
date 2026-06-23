class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> res;

        int carry = 1;
        


        for (int i = digits.size() -1; i >= 0; i--)
        {
            int num = digits[i] + carry;
            if (num == 10)
            {
                res.push_back(0);
            } else
            {
                res.push_back(num);
                carry = 0;
            }  
        } 

        if (carry)
        {
            res.push_back(carry);
        }

        std::reverse(res.begin(), res.end());

        return res; 
    }
};
