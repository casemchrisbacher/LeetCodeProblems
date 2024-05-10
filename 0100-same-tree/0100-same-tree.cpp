/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // DFS, checking each node as we go
    bool isSameTree( TreeNode* p, TreeNode* q ) 
    {
        // If both nodes are null, return true
        if ( p == nullptr && q == nullptr )
        {
            return true;
        }
        // If one is null and the other isn't, return false (miscompare)
        if ( p == nullptr || q == nullptr )
        {
            return false;
        }
        // If the values within the nodes aren't equal, return false
        if ( p->val != q->val )
        {
            return false;
        }
        // Pre Order recursive DFS
        return isSameTree( p->left, q->left ) && isSameTree( p->right, q->right );
    } // end of isSameTree
};  // end of Solution class