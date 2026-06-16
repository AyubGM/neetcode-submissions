class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";
        vector<int> sizes;
        for(string& s : strs)
        {
            sizes.push_back(s.size());
        }
        for ( int sz : sizes)
        {
            res += to_string(sz) + ',';
        }
        res += '#';

        for(string& s : strs)
        {
            res += s;
        }
        return res;

    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<string> res;
        vector<int> sizes;

        int i = 0;
        while(s[i] != '#')
        {
            string curr = "";
            while(s[i] != ',')
            {
                curr += s[i];
                i++;
            }

            sizes.push_back(stoi(curr));
            i++;//moving past the comma
        }
        i++; // moving past the #

        for(int sz : sizes)
        {
            res.push_back(s.substr(i,sz));
            i += sz; //moving the index from the previous string to the other one 
            //by adding the size of the current string to the index
        }        


        return res;
    }
};
