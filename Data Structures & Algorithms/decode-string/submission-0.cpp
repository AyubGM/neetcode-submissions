class Solution {
   public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currStr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(k);
                stringStack.push(currStr);

                currStr = "";
                k = 0;
            } else if (c == ']') {
                string prevStr = stringStack.top();
                stringStack.pop();
                int count = countStack.top();
                countStack.pop();

                string repeated = "";
                for (int i = 0; i < count; i++) {
                    repeated += currStr;
                }
                currStr = prevStr + repeated;
            } else {
                currStr += c;
            }
        }
        return currStr;
    }
};