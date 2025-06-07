# Three Sum Problem

## Problem Statement
Given an integer array `nums`, find all unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

Return all such unique triplets.

---

## Approach

1. **Sort the array** to enable two-pointer approach and easy duplicate skipping.
2. Iterate over the array with index `i`:
   - Skip duplicate values for `i` to avoid repeated triplets.
3. For each `i`, use two pointers `start` (initially `i+1`) and `end` (initially `n-1`):
   - Calculate `sum = nums[i] + nums[start] + nums[end]`.
   - If `sum == 0`, record the triplet and move both pointers, skipping duplicates.
   - If `sum < 0`, move `start` pointer forward to increase the sum.
   - If `sum > 0`, move `end` pointer backward to decrease the sum.
4. Continue until `start` meets `end`.
5. Return all unique triplets collected.

---

## Code Implementation

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int start = i + 1;
            int end = n - 1;

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    // Skip duplicates for start
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    // Skip duplicates for end
                    while (start < end && nums[end] == nums[end - 1]) end--;
                    start++;
                    end--;
                }
                else if (sum < 0) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
    }
};
