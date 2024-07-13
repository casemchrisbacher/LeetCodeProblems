class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int rolling_min{prices[0]};
        int rolling_profit{0};
        int profit{0};
        for ( const int price : prices )
        {
            if ( ( price - rolling_min ) > rolling_profit )
            {
                rolling_profit = ( price - rolling_min );
            }
            else
            {
                profit += rolling_profit;
                rolling_profit = 0;
                rolling_min = price;
            }
        }
        return (profit + rolling_profit);
    }
};