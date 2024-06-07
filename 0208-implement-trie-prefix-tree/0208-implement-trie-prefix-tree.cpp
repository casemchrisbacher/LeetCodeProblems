struct Node {
    std::vector<Node*> child{ 26, nullptr };
    bool lastChar{false};

    Node() {}
};

class Trie {
private: 
    Node* mRoot{ nullptr };

public:
    Trie() 
    {
        mRoot = new Node();
    }
    
    void insert( string word )
    {
        Node* cur_nod = mRoot;

        for ( const char& letter : word )
        {
            if ( cur_nod->child[ letter - 'a' ] == nullptr )
            {
                cur_nod->child[ letter - 'a' ] = new Node();
            }
            cur_nod = cur_nod->child[ letter - 'a' ];
        }
        cur_nod->lastChar = true;
    }
    
    bool search( string word )
    {
        Node* cur_nod = mRoot;

        for ( const char& letter : word )
        {
            if ( cur_nod->child[ letter - 'a' ] == nullptr )
            {
                return false;
            }
            cur_nod = cur_nod->child[ letter - 'a' ];
        }
        return cur_nod->lastChar;
    }
    
    bool startsWith( string prefix )
    {
        Node* cur_nod = mRoot;

        for ( const char& letter : prefix )
        {
            if ( cur_nod->child[ letter - 'a' ] == nullptr )
            {
                return false;
            }
            cur_nod = cur_nod->child[ letter - 'a' ];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */