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
    vector<int> rightSideView( TreeNode* root )
    {
        std::vector<int> right;
        if ( root == nullptr ) return right;

        std::queue<TreeNode*> q;
        q.push( root );

        while ( !q.empty() )
        {
            int Q_SIZE = q.size();
            for ( int i = 0; i < Q_SIZE; i++ )
            {
                TreeNode* top_node = q.front();
                q.pop();
                if ( top_node->left )
                    q.push( top_node->left );
                if ( top_node->right )
                    q.push( top_node->right );
                if ( i == Q_SIZE - 1 )
                {
                    right.push_back( top_node->val );
                }
            }
        }
        return right;
    }
};