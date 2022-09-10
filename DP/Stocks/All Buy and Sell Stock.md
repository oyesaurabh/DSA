#  Buy and Sell Stock 1
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

1 transaction possible

Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```
### Solution 
Time Complexity: O(N)<br>
Space Complexity: O(1)<br>
```cpp
class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        
        int maxProfit = 0;
        int buy = Arr[0];

        for(int i=1;i<Arr.size();i++){
            int curProfit = Arr[i] - buy;
            maxProfit = max(maxProfit,curProfit);
            buy = min(buy,Arr[i]);
        }
        return maxProfit;
    }
};
```
# Best Time to Buy and Sell Stock II
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

infinite transaction possible

Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```
### Solution
Time Complexity: O(N)<br>
Space Complexity: O(1)<br>
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We need prices for 2 days at least to find the profit.
        if (prices.empty() || prices.size() <= 1) {
            return 0;
        }

        int totalProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // Checking if we can profit with previous day's price.
            // If yes, then we buy on previous day and sell on current day.
            // Add all such profits to get the total profit.
            if (prices[i - 1] < prices[i]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};
```