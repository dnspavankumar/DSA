# Longest Consecutive Sequence

### Core Algorithm

1. **Insert all elements into a hash set** for O(1) lookup.
2. **Iterate through each number**, and only begin counting if `num - 1` is not in the set (ensures it's the start of a sequence).
3. **Count the streak** by checking `num + 1`, `num + 2`, ... in the set.
4. Track and return the **maximum streak length**.

### C++ Code

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int curr = num;
                int streak = 1;

                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
