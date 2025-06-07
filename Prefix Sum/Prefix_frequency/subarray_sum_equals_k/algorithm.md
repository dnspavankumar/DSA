# Subarray Sum Equals K

## Algorithm Steps

1. **Initialize Prefix Sum Frequency Map**  
   - Use a hash map `prefix_freq` to store how many times a prefix sum has occurred.
   - Initialize `prefix_freq[0] = 1` to account for subarrays that directly sum to `k`.

2. **Iterate Through Array and Track Prefix Sums**  
   - Maintain a running sum `sum`.
   - At each index, check if `sum - k` exists in `prefix_freq`. If so, a valid subarray ends at the current index.
   - Increment the frequency of the current `sum` in the map.

---

## Code Snippet

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_freq;
        prefix_freq[0] = 1; // empty subarray has sum 0

        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (prefix_freq.count(sum - k)) {
                count += prefix_freq[sum - k];
            }
            prefix_freq[sum]++;
        }
        return count;
    }
};
