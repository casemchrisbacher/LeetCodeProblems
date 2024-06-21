class Solution {
    void dfs( vector<int>& rNums, vector<vector<int>>& rSubSets, vector<int> curSet, int curIndex )
    {
        rSubSets.push_back( curSet );
        for ( int i = curIndex; i < rNums.size(); i++ )
        {
            std::vector<int> new_set = curSet;
            new_set.push_back( rNums[ i ] );
            dfs( rNums, rSubSets, new_set, i + 1 );
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<std::vector<int>> sub_sets;
        std::vector<int> cur_set;
        dfs( nums, sub_sets, cur_set, 0 );
        return sub_sets;
    }
};