# Dutch National Flag Algorithm

### 🔧 Core Algorithm (2 Steps)

1. **Maintain three pointers**:  
   - `low` → boundary for 0s  
   - `mid` → current element  
   - `high` → boundary for 2s  

2. **Traverse with `mid` pointer**:  
   - If `nums[mid] == 0`: swap with `low`, increment both `low` and `mid`  
   - If `nums[mid] == 1`: just increment `mid`  
   - If `nums[mid] == 2`: swap with `high`, decrement `high`

---

### 💡 C++ Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
