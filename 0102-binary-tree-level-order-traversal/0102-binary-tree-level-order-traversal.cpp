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
    vector<vector<int>> levelOrder( TreeNode* root )
    {
        vector<vector<int>> levels;
        vector<int> one_level;
        if ( root == nullptr ) return levels;

        queue<TreeNode*> q;
        q.push( root );

        while ( !q.empty() )
        {
            const int Q_SIZE = q.size();

            for ( int ind = 0; ind < Q_SIZE; ind++ )
            {
                TreeNode* copy_node = q.front();
                one_level.push_back( copy_node->val );
                q.pop();
                if ( copy_node->left != nullptr )
                {
                    q.push( copy_node->left );
                }
                if ( copy_node->right != nullptr )
                {
                    q.push( copy_node->right );
                }
            }
            levels.push_back( one_level );
            one_level.clear();
        }
        return levels;
    } // end of levelOrder
}; // end of Solution class