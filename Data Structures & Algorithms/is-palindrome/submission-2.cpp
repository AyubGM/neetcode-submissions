class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j)
        {
            if(!std::isalnum(s[i]))
            {
                i++;
                continue;
            }

            if(!std::isalnum(s[j]))
            {
                j--;
                continue;
            }

            if(std::tolower(s[i]) != std::tolower(s[j]))
            return false;

            i++;
            j--;
        }

        return true;
    }
};
