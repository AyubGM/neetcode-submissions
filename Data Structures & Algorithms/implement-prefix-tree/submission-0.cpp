struct TrieNode
{
    bool EndOfWord = false;
    std::unordered_map<char, TrieNode*> Children;
};

class PrefixTree {
  TrieNode* m_Root;
public:
    PrefixTree() : m_Root(new TrieNode()) {
    
    }
    
    void insert(string word) {
        TrieNode* curr = m_Root;

        for(char c : word)
        {
            if (!curr->Children.count(c))
            {
                curr->Children[c] = new TrieNode();
            }
            curr = curr->Children[c];
        }
        curr->EndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = m_Root;

        for(char c : word)
        {
            if (!curr->Children.count(c))
            {
                return false;
            }
             curr = curr->Children[c];
        }

        return curr->EndOfWord;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = m_Root;

        for(char c : prefix)
        {
            if (!curr->Children.count(c))
            {
                return false;
            }
             curr = curr->Children[c];
        }

        return true;
    }
};
