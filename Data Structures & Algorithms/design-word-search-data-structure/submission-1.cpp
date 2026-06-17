struct TrieNode 
{
    bool EndOfWord = false;
    std::unordered_map<char, TrieNode*> Children;
};

class WordDictionary {
    TrieNode* m_Root;

    bool SearchInNode(string word, int index, TrieNode* curr)
    {
        if (index == word.length())
        {
            return curr->EndOfWord;
        }

        char c = word[index];

        if(c == '.')
        {
            for(auto const& [key, val] : curr->Children )
            {
                if(SearchInNode(word, index + 1, val))
                {
                    return true;
                }
            }
            return false;
        } else
        {
            if(!curr->Children.contains(c))
            {
                return false;
            }
            
            return SearchInNode(word, index + 1, curr->Children[c]);
        }
    }
public:
    WordDictionary() : m_Root(new TrieNode()) {
        
    }
    
    void addWord(string word) {
        TrieNode* curr = m_Root;

        for (char c : word)
        {
            if (!curr->Children.contains(c))
            {
                curr->Children[c] =  new TrieNode();
            }
            curr = curr->Children[c];
        }
        curr->EndOfWord = true;
    }
    
    bool search(string word) {
       return SearchInNode(word, 0, m_Root);
    }
};
