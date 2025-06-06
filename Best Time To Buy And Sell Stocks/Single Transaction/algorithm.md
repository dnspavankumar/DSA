# 📈 Best Time to Buy and Sell Stock (Leetcode 121)

### 🧠 Problem Situation

You are given an array `prices[]`, where `prices[i]` is the price of a stock on day `i`.  
You can **buy and sell once** — buy on one day and sell on a future day.

**Goal**: Maximize profit.  
If no profit is possible, return `0`.

---

### ⚙️ Algorithm (Greedy, One Pass)

1. **Track `minPrice` seen so far**
2. For each day:
   - Compute profit if selling today: `prices[i] - minPrice`
   - Update `maxProfit` if this is the best profit so far

---

### 💡 C++ Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(prices[i], minPrice);  // update lowest price seen so far
            maxProfit = max(maxProfit, prices[i] - minPrice);  // best profit if sold today
        }
        return maxProfit;
    }
};
