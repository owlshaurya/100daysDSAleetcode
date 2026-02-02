int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // Update minimum price so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate profit if sold today
        int profit = prices[i] - minPrice;

        // Update maximum profit
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}
