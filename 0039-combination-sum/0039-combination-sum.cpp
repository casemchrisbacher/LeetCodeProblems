class Solution {
    void backTrack( vector<int>& rCanid, vector<vector<int>>& rWinners, int curInd,  vector<int> curSet, int target )
    {
        if ( target == 0 )
        {
            rWinners.push_back( curSet );
            return;
        }
        if ( target < 0 ) return;

        for ( int i = curInd; i < rCanid.size(); i++ )
        {
            curSet.push_back( rCanid[ i ] );
            backTrack( rCanid, rWinners, i, curSet, target - rCanid[ i ] );
            curSet.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        std::vector<std::vector<int>> winners;
        std::vector<int> temp_set;

        backTrack( candidates, winners, 0, temp_set, target );
        return winners;
    }
};