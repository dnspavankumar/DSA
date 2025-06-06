# ⚡ Kadane's Algorithm (Return Max Sum + Indices)

### 🔧 Core Algorithm (2 Steps)

1. **Iterate through array** maintaining:
   - `curr_sum`: sum of the current subarray
   - `max_sum`: highest sum found
   - `start`, `end`: indices of the max subarray
   - `temp_start`: candidate starting index

2. **Logic**:
   - If `curr_sum < 0`, reset the subarray to start at current index
   - If `curr_sum > max_sum`, update `max_sum` and index boundaries

---

### 💡 C++ Code

```cpp
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];
        int start = 0, temp_start = 0, end = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (curr_sum < 0) {
                curr_sum = nums[i];
                temp_start = i;
            } else {
                curr_sum += nums[i];
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                start = temp_start;
                end = i;
            }
        }

        // Return vector: {maximum sum, start index, end index}
        return {max_sum, start, end};
    }
};
