class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        for(char c : s){
            size_t pos = t.find(c);
            if(pos != string::npos) {
                t.erase(pos,1);
            } else {
                return false;
            }
        }
        return t.empty();
    }
};
