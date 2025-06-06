
## Algorithm (Hash Map Approach)

1. Iterate over the array.
2. For each element `nums[i]`, check if `target - nums[i]` exists in the hash map.
3. If it exists, return the pair of indices.
4. Otherwise, store the current element and its index in the hash map.
5. If no pair is found, return `{-1}`.

## Code Snippet

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mp;
       for (int i = 0; i < nums.size(); i++) {
           int complement = target - nums[i];
           if (mp.count(complement)) {
               return {mp[complement], i};
           }
           mp[nums[i]] = i;
       }
       return {-1};
    }
};
