
### Step 1: Compute Prefix Sums

```cpp
prefix_sum[i + 1] = prefix_sum[i] + arr[i];
```

### Step 2: Use Hash Map to Track First Occurrences

```cpp
if (prefix_sum[i] - k) exists in map:
    update maximum length

if prefix_sum[i] not in map:
    store it with index i
```

---

## 💻 Code Implementation

```cpp
int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prefix_sum(n + 1, 0);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    int maximum_size = 0;

    for (int i = 0; i <= n; i++) {
        if (mp.count(prefix_sum[i] - k)) {
            maximum_size = max(maximum_size, i - mp[prefix_sum[i] - k]);
        }
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

* `prefix_sum[3] - prefix_sum[0] = 6` → subarray `[1, 2, 3]`
* `prefix_sum[5] - prefix_sum[2] = 6` → subarray `[3, -2, 5]`

Maximum length = `3`.

---

## ✅ Summary

This approach optimizes the naive solution by using **prefix sums and a hash map** to track previous subarray sums, allowing us to solve the problem in linear time.

---
