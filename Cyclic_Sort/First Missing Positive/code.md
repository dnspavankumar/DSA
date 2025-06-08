# First Missing Positive - Cyclic Sort Based Solution

## Problem Statement
Given an unsorted integer array, find the smallest missing positive integer.

You must implement an algorithm that runs in `O(n)` time and uses constant extra space.

## Approach: Cyclic Sort (In-place)

We use the **cyclic sort** technique to place each positive number `x` (where `1 <= x <= n`) at index `x-1`.

### Steps:
1. Iterate through the array.
2. While the current number is in the valid range (`1` to `n`) and is not at its correct position (i.e., `nums[nums[i] - 1] != nums[i]`), **swap it with the number at its target index**.
3. After this rearrangement, traverse the array again:
   - The **first index** `i` where `nums[i] != i + 1` means `i + 1` is the smallest missing positive.
4. If all elements are correctly placed, return `n + 1`.

## C++ Code

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Place nums[i] at the correct index if it's in the range [1, n]
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // After placement, the first index where nums[i] != i + 1 is the answer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // All numbers are in place
        return n + 1;
    }
};
