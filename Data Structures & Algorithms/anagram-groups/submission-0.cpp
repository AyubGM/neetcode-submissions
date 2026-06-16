class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){ 
            string eachString = s; //eachString aka key
             //sorting each string in the array to get key
            sort(eachString.begin(),eachString.end());
            mp[eachString].push_back(s);
        }

        vector<vector<string>> result;
        for(auto pair:mp){
            result.push_back(pair.second);
        }
        return result;
    }
};
