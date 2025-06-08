# 📌 Smallest Subarray with Sum Greater Than X

## 🧩 Problem Statement

Given an array `arr[]` of size `n` and a value `x`, find the **length of the smallest subarray** with **sum greater than `x`**.

If no such subarray exists, return 0.

---

## 💡 Approach

This solution uses the **sliding window technique** to efficiently find the minimum length subarray that satisfies the condition.

### 🔄 Steps:
1. Initialize two pointers `i` and `j` to 0.
2. Use `j` to expand the window and accumulate the sum in `total`.
3. Once `total > x`, attempt to shrink the window from the left (`i++`) while maintaining the condition.
4. At each valid point, update the result `ans` with the minimum window size.
5. After traversal, return `0` if no such subarray exists.

---

## ✅ Code (C++)

```cpp
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int ans = arr.size() + 1;
        int i = 0, j = 0;
        int n = arr.size();
        int total = 0;

        while (j < n) {
            total += arr[j];

            while (total > x) {
                ans = min(ans, j - i + 1);
                total -= arr[i];
                i++;
            }
            j++;
        }

        if (ans == n + 1) return 0;
        return ans;
    }
};
