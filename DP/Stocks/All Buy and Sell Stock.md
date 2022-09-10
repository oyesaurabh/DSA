#  1. Buy and Sell Stock 1
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

1 transaction possible

Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```
### Solution :: Greedy
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
# 2. Best Time to Buy and Sell Stock II
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
### Solution :: greedy
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
### Solution :: memoization
Time Complexity: O(N^2)<br>
Space Complexity: O(N^2) + O(N)<br>
```cpp
    int fun(vector<int>&a, int i, bool canBuy, vector<vector<int>>& dp){
        if(i==a.size())return 0;
        
        if(dp[i][canBuy] != -1)return dp[i][canBuy];
        
        if(canBuy)//                    buying so -a[i]
            return dp[i][canBuy]=max( fun(a,i+1,0,dp)-a[i], fun(a,i+1,1,dp)-0 );
        else //                         selling so +a[i]
            return dp[i][canBuy]=max( fun(a,i+1,1,dp)+a[i], fun(a,i+1,0,dp)+0 );
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(prices,0,1,dp);
    }
```
### Solution :: Tabulation
Time Complexity: O(N^2)<br>
Space Complexity: O(N^2)<br>
```cpp
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
            for(int buy=0;buy<=1;buy++){
                if(buy)//       buy so -a[i]
                    dp[i][buy]=max( dp[i+1][0]-a[i], dp[i+1][1] );
                else //            selling so +a[i]
                    dp[i][buy]=max( dp[i+1][1]+a[i], dp[i+1][0]);
            }
        return dp[0][1];
    }
```
# 3. Best Time to Buy and Sell Stock III
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

can do at most 2 transactions.

Example 1:
```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```
### Solution
Time Complexity: O(N)<br>
Space Complexity: O(1)<br>
```cpp

```