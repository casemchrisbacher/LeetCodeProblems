/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfsCloneGraph( Node* pOrig, Node* pClone, std::unordered_map<Node*, Node*> &rVisited )
    {
        if ( pOrig == nullptr || pClone == nullptr ) return;

        for ( const auto & neighbor : pOrig->neighbors )
        {
            if ( rVisited.find( neighbor ) == rVisited.end() )
            {
                Node* neigh_copy = new Node( neighbor->val );
                rVisited[ neighbor ] = neigh_copy;
                pClone->neighbors.push_back( neigh_copy );
                dfsCloneGraph( neighbor, neigh_copy, rVisited );
            }
            else
            {
                pClone->neighbors.push_back( rVisited[ neighbor ] );
            }
        }
    }
public:
    Node* cloneGraph( Node* node )
    {
        if ( node == nullptr ) return nullptr;

        unordered_map<Node*, Node*> visited;
        Node* clone = new Node( node->val );
        visited[ node ] = clone;
        dfsCloneGraph( node, clone, visited );
        return clone;
    }
};