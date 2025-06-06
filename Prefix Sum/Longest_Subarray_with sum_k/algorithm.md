# 📌 Longest Subarray with Sum Equal to K

## 🧠 Problem Statement

Given an array of integers `arr[]` and an integer `k`, return the **length of the longest subarray** whose sum equals `k`.

---

## 💡 Intuition

We want to find the longest subarray whose sum is exactly equal to `k`. The **brute force** way would be to check every subarray, compute its sum, and compare — but that takes **O(n²)** time.

Instead, we can use **prefix sums** and a **hash map** to reduce the complexity to **O(n)**.

---

## 🛮︎ Key Observations

* If `prefix_sum[i] - prefix_sum[j] = k`, then the subarray `arr[j to i-1]` has a sum of `k`.
* We can keep track of **first occurrences** of prefix sums using a hash map.
* This helps us calculate the length of subarrays ending at any index `i` efficiently.

---

## 🚀 Algorithm

### Step 1: Compute Prefix Sums

We create a prefix sum array such that:

```cpp
prefix_sum[i + 1] = prefix_sum[i] + arr[i];
```

This allows quick calculation of subarray sums using:

```cpp
sum(i, j) = prefix_sum[j+1] - prefix_sum[i];
```

### Step 2: Use a Hash Map

We use an unordered map to store the **first occurrence** of each prefix sum.

If we find:

```cpp
prefix_sum[i] - k = some previous prefix sum,
```

then we've found a subarray of sum `k`, and we compute its length:

```cpp
length = i - mp[prefix_sum[i] - k];
```

We keep track of the **maximum length** found this way.

---

## 💻 Code Implementation

```cpp
int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prefix_sum(n + 1, 0);
    unordered_map<int, int> mp;

    // Step 1: Compute prefix sum
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    int maximum_size = 0;

    // Step 2: Iterate and use hashmap
    for (int i = 0; i <= n; i++) {
        if (mp.count(prefix_sum[i] - k)) {
            maximum_size = max(maximum_size, i - mp[prefix_sum[i] - k]);
        }

        // Store only the first occurrence
        if (mp.find(prefix_sum[i]) == mp.end()) {
            mp[prefix_sum[i]] = i;
        }
    }

    return maximum_size;
}
```

---

## ⏱️ Time and Space Complexity

| Metric           | Value  |
| ---------------- | ------ |
| Time Complexity  | `O(n)` |
| Space Complexity | `O(n)` |

* Prefix sum calculation is `O(n)`.
* Hash map operations are `O(1)` on average.

---

## 📌 Example

### Input:

```cpp
arr = [1, 2, 3, -2, 5], k = 6
```

### Prefix Sum:

```
[0, 1, 3, 6, 4, 9]
```

* `prefix_sum[3] - prefix_sum[0] = 6 - 0 = 6` → subarray `[1, 2, 3]`
* `prefix_sum[5] - prefix_sum[2] = 9 - 3 = 6` → subarray `[3, -2, 5]`

Maximum length = `3`.

---

## ✅ Summary

This approach optimizes the naive solution by using **prefix sums and a hash map** to track previous subarray sums, allowing us to solve the problem in linear time.

It’s a powerful technique applicable in many problems involving subarrays with a given sum.

---
