class Solution {
    void backTrack( vector<int>& rNums, vector<vector<int>>& rPerms, vector<int> curSet, int curInd )
    {
        if ( rNums.size() == curSet.size() )
        {
            rPerms.push_back( curSet );
        }

        for ( int i = 0; i < rNums.size(); i++ )
        {
            if ( std::find( curSet.begin(), curSet.end(), rNums[ i ] ) == curSet.end() )
            {
                curSet.push_back( rNums[ i ] );
                backTrack( rNums, rPerms, curSet, i + 1 );
                curSet.pop_back();
            }
            // backTrack( rNums, rPerms, curSet, i + 1 );
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> perms;
        std::vector<int> copy_set;
        
        backTrack( nums, perms, copy_set, 0 );
        return perms;
    }
};