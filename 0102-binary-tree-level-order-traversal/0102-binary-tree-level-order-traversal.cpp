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
        queue<TreeNode*> q;
        if ( root == nullptr ) return levels;
        q.push( root );

        while ( !q.empty() )
        {
            const int Q_SIZE = q.size();
            for ( int i = 0; i < Q_SIZE; i++ )
            {
                TreeNode* temp = q.front();
                q.pop();
                one_level.push_back( temp->val );

                if ( temp->left != nullptr ) q.push( temp->left );
                if ( temp->right != nullptr ) q.push( temp->right );
            }
            levels.push_back( one_level );
            one_level = {};
        }

        return levels;
    } // end of levelOrder
}; // end of Solution class