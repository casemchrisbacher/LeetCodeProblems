class Solution {
public:
    // Want to find the min price as we go
    int maxProfit( vector<int>& prices ) 
    {
        int max_profit{0};          // Can set this to 0
        int min_price = prices[0];  // We know prices.size() > 0
        for ( const auto & cur_price : prices )
        {
            // if this is the minimum element so far, set it to the min
            min_price = std::min( min_price, cur_price );
            // if the current price - min price (so far) is less than prev max, update it
            max_profit = std::max( max_profit, cur_price - min_price );
        }
        return max_profit;
    } // end of maxProfit
}; // end of Soltuion class