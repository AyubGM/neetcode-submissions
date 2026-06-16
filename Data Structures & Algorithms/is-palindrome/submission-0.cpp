class Solution {
public:
    bool isPalindrome(string s) {
        int f = 0;
        int e = s.length() - 1;

        while(f < e)
        {
            while(!alphaNum(s[f]) && f < e)//if it was empty space or invalid
            {
                f++;
            }
            while(!alphaNum(s[e]) && e > f)//if it was empty space or invalid
            {
                e--;
            }
            if(tolower(s[f]) != tolower(s[e]))
            {
                return false;
            }
            f++;
            e--;
        }
        return true;

    }

    bool alphaNum(char c)
    {
        return (c >= 'A' && c <= 'Z' ||
        c >= 'a' && c <= 'z'||
        c >= '0' && c <= '9'
        );
    }
};
