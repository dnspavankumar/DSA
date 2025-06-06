# Two Sum (Sorted Array) — Two Pointer Approach

## Algorithm
- Initialize two pointers: `left` at start, `right` at end.
- While `left < right`:
  - Calculate `sum = arr[left] + arr[right]`.
  - If `sum == target`, return `{left + 1, right + 1}`.
  - If `sum < target`, increment `left`.
  - Else decrement `right`.
- Return `{-1}` if no pair found.

## Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) return {left + 1, right + 1};
            else if (sum < target) left++;
            else right--;
        }
        return {-1};
    }
};
