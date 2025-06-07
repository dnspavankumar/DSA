# Majority Element II Algorithm

## Problem
Find all elements in an integer array `nums` that appear more than ⌊ n/3 ⌋ times, where `n` is the size of the array.

## Approach
- Use a hash map (`unordered_map`) to count the frequency of each element.
- Traverse the array once to build the frequency map.
- Traverse the frequency map to find all elements whose frequency is greater than `n/3`.
- Return these elements in a result vector.

## Time Complexity
- O(n), where `n` is the number of elements in `nums`.

## Space Complexity
- O(n) for storing frequencies in the worst case.

---

## Code Implementation

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;
        int n = nums.size();

        // Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        // Collect elements appearing more than n/3 times
        for (auto& it : freq) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
