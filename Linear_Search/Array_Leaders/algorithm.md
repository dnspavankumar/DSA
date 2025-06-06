# ⭐ Leaders in an Array

### 🧠 Problem Statement

Given an integer array `arr[]`, a **leader** is an element that is **greater than or equal to all elements to its right**.  
- By definition, the rightmost element is always a leader.

**Task**: Return a list of all leaders from left to right.

---

### ⚙️ Algorithm (Right-to-Left Scan)

1. **Initialize**
   - Let `n = arr.size()`.
   - Set `right_max = arr[n - 1]` (the last element).
   - Create an empty vector `ans` and push `right_max` (since the last element is always a leader).

2. **Traverse from second-last down to the first element**:
   ```cpp
   for (int i = n - 2; i >= 0; --i) {
       if (arr[i] >= right_max) {
           ans.push_back(arr[i]);
           right_max = arr[i];
       }
   }
