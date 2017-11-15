class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int profit = -1;
        for(int i = 0; i < prices.size() - 1; i++) {
            int maxium = prices[i];
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] > maxium) maxium = prices[j];
            }
            if((maxium - prices[i]) > profit) profit = maxium - prices[i];
        }
        return profit;
    }
};