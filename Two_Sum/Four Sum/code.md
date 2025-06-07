# Four Sum Problem

## Problem Statement

Given an integer array `nums` and an integer `target`, return all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `a`, `b`, `c`, and `d` are distinct indices,
- `nums[a] + nums[b] + nums[c] + nums[d] == target`.

The solution set must not contain duplicate quadruplets.

---

## Approach

1. **Sort the array** to make it easier to avoid duplicates and use two-pointer technique.
2. Use two nested loops to fix the first two elements (`k` and `i`).
3. For the remaining two elements, use two pointers (`start` and `end`) to find pairs that sum up to `target - (nums[k] + nums[i])`.
4. Skip duplicates for all four elements to avoid repeated quadruplets.
5. Use `long long` when calculating the sum to avoid integer overflow.

---

## Code Implementation

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int k = 0; k < n; k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;  // Skip duplicate for k

            for (int i = k + 1; i < n; i++) {
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;  // Skip duplicate for i

                int start = i + 1, end = n - 1;
                while (start < end) {
                    long long sum = (long long)nums[k] + nums[i] + nums[start] + nums[end];

                    if (sum == target) {
                        ans.push_back({nums[k], nums[i], nums[start], nums[end]});

                        // Skip duplicates for start and end
                        while (start < end && nums[start] == nums[start + 1]) start++;
                        while (start < end && nums[end] == nums[end - 1]) end--;

                        start++;
                        end--;
                    }
                    else if (sum < target) {
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
