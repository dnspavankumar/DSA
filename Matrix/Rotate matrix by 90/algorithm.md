# Rotate Image (90 Degrees Clockwise) - In-place Solution

## Algorithm Steps

1. **Transpose the matrix**  
   Swap elements `matrix[i][j]` with `matrix[j][i]` for all `j < i`.

2. **Reverse each row**  
   Reverse the elements in every row to complete the 90-degree clockwise rotation.

---

## Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Step 1: Transpose the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
