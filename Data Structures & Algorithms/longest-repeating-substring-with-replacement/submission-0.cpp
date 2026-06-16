class Solution {
public:
    int characterReplacement(string s, int k) {        
        std::unordered_map<char,int> frq;
        int res = 0;
        int l = 0;

        for(int r = 0; r < s.length(); r++)
        {
            frq[s[r]]++;

            auto maxFrq = std::max_element(frq.begin(),frq.end(), 
            [](const auto& a, const auto& b) {return a.second < b.second;});

            int windowSize = r - l + 1;
            if (( windowSize -  maxFrq->second) > k)
            {
                frq[s[l]]--;
                l++;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
