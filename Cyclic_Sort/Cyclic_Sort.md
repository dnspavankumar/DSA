# Cyclic Sort Algorithm (First Missing Positive)

## Problem

Find the **first missing positive integer** from an unsorted array of integers.

### Example

```cpp
Input: [3, 4, -1, 1]
Output: 2
```

## Code (C++)

```cpp
int n = nums.size();
for (int i = 0; i < nums.size(); i++) {
    while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
    }
}
```

## Explanation

This approach is based on the **Cyclic Sort** pattern and works in-place with `O(n)` time complexity.

### Goal:

Place each number `x` (where `1 <= x <= n`) at index `x - 1`.

### Key Condition in `while`:

```cpp
nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]
```

* `nums[i] > 0 && nums[i] <= n`: Only consider values in the valid range.
* `nums[nums[i] - 1] != nums[i]`: Avoid unnecessary swaps for duplicates or already placed elements.

### Swapping:

Moves `nums[i]` to its correct position: index `nums[i] - 1`.

### After Sorting:

Loop through the array again:

```cpp
for (int i = 0; i < n; i++) {
    if (nums[i] != i + 1) return i + 1;
}
```

This identifies the first index where the expected value is missing.

## Time & Space Complexity

* **Time**: O(n)
* **Space**: O(1) (in-place)

## Use Case

This technique is optimal for problems where:

* Values are within a specific range (e.g., 1 to n).
* We need constant space.
* We must find a missing/duplicate element.
