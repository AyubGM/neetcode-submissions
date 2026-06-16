class Solution {
public:
    bool isValid(string s) {
       std::vector<char> brakets;

       for(char c : s)
       {
         if(c == '[' ||  c == '{'  || c == '(')
         {
            brakets.push_back(c);
         } else
         {
            if(brakets.empty()) return false;

            char open = brakets.back();
            brakets.pop_back();

            if(open == '[' && c != ']') return false;
            if(open == '{' && c != '}') return false;
            if(open == '(' && c != ')') return false;
         }

       }
       return brakets.empty();
    }
};
