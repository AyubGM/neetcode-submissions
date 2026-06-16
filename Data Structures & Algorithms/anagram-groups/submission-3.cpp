class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
       
        for(const auto& s : strs){
            vector<int> count(26,0); //to find value for each key for the hashmap
            for(char c: s ){
                count[c - 'a']++;//at this index we increment 
            }
            string key = to_string(count[0]); //key
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> result; //returning the list without the key
        for(const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
