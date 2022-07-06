[Link](https://leetcode.com/problems/coin-change-2/)
# Coin Change 2
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
### ***In short : Total number of ways***

```
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```
## Recursive
```cpp
class Solution {
    int n;
    int solve(vector<int>& a,int t,int size){
        if(t==0)
            return 1;
        if(size<0)return 0;
        
        if(a[size] <= t)
            return solve(a,t-a[size],size)+solve(a,t,size-1); //take both
        else
            return solve(a,t,size-1); // ignore
    }
public:
    int change(int t, vector<int>& a) {
        n=a.size();
        return solve(a,t,n-1);
    }
};
```
## Memoization
```cpp
class Solution {
    int n;
    int dp[301][5001];
    int solve(vector<int>& a,int t,int size){
        if(t==0)return 1;
        if(size<0)return 0;
        
        if(dp[size][t] != -1)return dp[size][t];
        if(a[size] <= t)
            return dp[size][t]=solve(a,t-a[size],size)+solve(a,t,size-1); //take both
        else
            return dp[size][t]=solve(a,t,size-1); // ignore
    }
public:
    int change(int t, vector<int>& a) {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return solve(a,t,n-1);
    }
};
```
## DP
```cpp

```