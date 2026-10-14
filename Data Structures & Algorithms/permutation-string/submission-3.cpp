class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if (n1 > n2) return false;

        std::array<int, 26> s1_count{0};
        std::array<int, 26> window_count{0};

        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }

        if (s1_count == window_count) return true;
        for (int i = n1; i < n2; i++)
        {
             window_count[s2[i] - 'a']++;

             window_count[s2[i - n1] - 'a']--;

             if (s1_count == window_count) return true;
        }
        
        return false;

    }
};
