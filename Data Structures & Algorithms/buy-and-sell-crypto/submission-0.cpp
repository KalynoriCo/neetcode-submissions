class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int best = 0;
    for (int i = 1; i < prices.size(); i++) {
        best = max(best, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return best;
    }
};
