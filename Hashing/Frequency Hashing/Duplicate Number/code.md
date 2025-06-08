# Find the Duplicate Number - Using Hash Map

## Problem Statement
Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive:

There is **only one duplicate number**, but it might be repeated more than once. Return the **duplicate** number.

## Approach: Frequency Count Using Hash Map

We use an **unordered map (hash map)** to count the frequency of each number. If any number occurs more than once, it is the duplicate.

### Steps:
1. Initialize an empty hash map `freq`.
2. Traverse the array:
   - For each element `num`, increment `freq[num]`.
3. Traverse the map:
   - If the frequency of a number is greater than 1, return it as the duplicate.
4. If no duplicate is found (should not happen per problem constraint), return `-1`.

## C++ Code

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (pair<int, int> it : freq) {
            if (it.second > 1)
                return it.first;
        }

        return -1; // Default case, not expected to be reached
    }
};
