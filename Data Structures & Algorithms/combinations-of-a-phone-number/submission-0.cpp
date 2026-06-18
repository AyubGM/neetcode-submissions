class Solution {
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};

    void Backtrack(int i, string sub,string& digits)
    {
        if (sub.size() == digits.size())
        {
            res.push_back(sub);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];

        for (char c : chars)
        {
            Backtrack(i + 1, sub + c, digits);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;

        Backtrack(0, "", digits);

        return res;
    }
};
